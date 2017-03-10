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

#include "DTLS.h"

#include "inet/security/DTLS/recordLayer/DTLSRecord_m.h"

namespace inet {

namespace dtls {

Define_Module(DTLS);

DTLS::DTLS()
{
    recordLayer = nullptr;
}

DTLS::~DTLS()
{
    delete recordLayer;
}

void DTLS::initialize()
{
    recordLayer = new DTLSRecordLayer();
}

void DTLS::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        std::cout<<"SelfMessage\n";
    else if (msg->arrivedOn("dtls_udpIn"))
        processMsgFromLowerLayer(msg);
    else
        processMsgFromHigherLayer(msg); 
}


void DTLS::processMsgFromLowerLayer(cMessage *packet)
{
    int gateIndex = packet->getArrivalGate()->getIndex(); 
    
    if (packet->isPacket()) {
        if (dynamic_cast<DTLSRecord *>(packet)) {
            DTLSRecord *record = check_and_cast<DTLSRecord *> (packet);      
            cPacket *appData = recordLayer->processDTLSRecord(record);
            if (appData != NULL)      
                send(appData, "dtls_appOut", gateIndex);
        }
        else {
            throw cRuntimeError("DTLS does not receive DTLSRecord packet.");
            //send(packet, "tls_appOut", gateIndex);
       }
    }
    else { //msg from tcp to socket
        send(packet, "dtls_appOut", gateIndex);
    }
        
}

void DTLS::processMsgFromHigherLayer(cMessage *packet)
{
    int gateIndex = packet->getArrivalGate()->getIndex(); 
    
    if (packet->isPacket()) {
        // call TLS Record Layer (fragmentation, compression, encryption..) 
        DTLSRecord *record = recordLayer->prepareDTLSRecord(check_and_cast<cPacket *> (packet)); 
        send(record, "dtls_udpOut", gateIndex); // forward the packet to the TCP
    }
    else { // this is not app packet. forward to tcp
        send(packet,"dtls_udpOut", gateIndex);
    }
}

} //dtls

} //inet


            
