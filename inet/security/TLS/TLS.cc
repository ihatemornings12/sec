//
// Copyright (C) <2017>  <Alexandra Stagkopoulou>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "TLS.h"

#include "inet/security/TLS/TLSRecord_m.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"

namespace inet {

namespace tls {

Define_Module(TLS);

TLS::TLS()
{
    recordLayer = nullptr;
}

TLS::~TLS()
{
    delete recordLayer;
}

void TLS::initialize()
{
    recordLayer = new TLSRecordLayer();
}

void TLS::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        std::cout<<"SelfMessage\n";
    else if (msg->arrivedOn("tls_tcpIn"))
        processMsgFromLowerLayer(msg);
    else
        processMsgFromHigherLayer(msg); 
}


void TLS::processMsgFromLowerLayer(cMessage *packet)
{
    int gateIndex = packet->getArrivalGate()->getIndex(); 
    
    if (packet->isPacket()) {
        if (dynamic_cast<TLSRecord *>(packet)) {
            TLSRecord *record = check_and_cast<TLSRecord *> (packet);      
            cPacket *appData = recordLayer->processTLSRecord(record);              
            send(appData, "tls_appOut", gateIndex);
        }
        else {
            //throw cRuntimeError("TLS does not receive TLSRecord packet.");
            send(packet, "tls_appOut", gateIndex);
        }
    }
    else { //msg from tcp to socket
        send(packet, "tls_appOut", gateIndex);
    }
        
}

void TLS::processMsgFromHigherLayer(cMessage *packet)
{
    int gateIndex = packet->getArrivalGate()->getIndex(); 
    
    if (packet->isPacket()) {
     // call TLS Record Layer (fragmentation, compression, encryption..) 
        TLSRecord *record = recordLayer->prepareTLSRecord(check_and_cast<cPacket *> (packet)); 
        send(record, "tls_tcpOut", gateIndex); // forward the packet to the TCP
    }
    else { // this is not app packet. forward to tcp
        send(packet,"tls_tcpOut", gateIndex);
    }
}

} //tls

} //inet


            
