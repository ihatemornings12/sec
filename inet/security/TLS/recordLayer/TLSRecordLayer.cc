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

#include "TLSRecordLayer.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
#include "inet/applications/tcpapp/GenericAppMsg_m.h"

namespace inet {

namespace tls {

TLSRecordLayer::TLSRecordLayer()
{
}

TLSRecordLayer::~TLSRecordLayer()
{
}

TLSRecord *TLSRecordLayer::prepareTLSRecord(cPacket *appData) 
{            
    TLSRecord *tlsRecord = new TLSRecord("TLS_Record");
    tlsRecord->setByteLength(TLS_HEADER);
    
    tlsRecord->setKind(appData->getKind());
    tlsRecord->setType(APPLICATION_DATA);
    //version: TODO: TO BE CHANGED
    ProtocolVersion version = {};
    version.major = TLS_VERSION;
    version.minor = TLS_VERSION;
    tlsRecord->setVersion(version);

    TCPCommand *controlInfo = check_and_cast<TCPCommand *> (appData->removeControlInfo());
    tlsRecord->setControlInfo(controlInfo);
    
    //------- TLS RECORD LAYER OPERATIONS ---------------//
        
    //1. Fragmentation:TODO Handle payload bigger than 2^14B      
    ASSERT(appData->getByteLength() <= TLS_MAX_PLAINTEXT_LENGTH);
    
    //2. Compression:'CompressionMethod.null' is considered so, no compression is performed. Compressed Fragment no bigger than (2^14+1024)B
    
    //3. Encryption
    //3.a Compute MAC-> default SHA_256 (32bits). Seq number is defined
    //3.b Encrypt
    
    tlsRecord->encapsulate(appData);
    return tlsRecord;
}

cPacket *TLSRecordLayer::processTLSRecord(TLSRecord *tlsRecord) 
{
    if (tlsRecord->getType() == APPLICATION_DATA) {
        cPacket *appData = tlsRecord->decapsulate();
        appData->setKind(tlsRecord->getKind());
        TCPCommand *controlInfo = check_and_cast<TCPCommand *> (tlsRecord->removeControlInfo()); 
        appData->setControlInfo(controlInfo);
        delete tlsRecord;
        return appData;
    }
    else {
        throw cRuntimeError("TLS Record Layer handles only Application Data.");
        delete tlsRecord;
    }
   
}

} //tls

} //inet
