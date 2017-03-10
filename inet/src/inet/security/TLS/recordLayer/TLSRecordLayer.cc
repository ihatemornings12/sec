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
#include "ConnectionStates_m.h"
#include "inet/applications/tcpapp/GenericAppMsg_m.h"

namespace inet {

namespace tls {

TLSRecordLayer::TLSRecordLayer()
{
    version.major = TLS_VERSION;
    version.minor = TLS_VERSION;
    
    sequence_number = 0;
    sequence_number_prev = -1;
}

TLSRecordLayer::~TLSRecordLayer()
{
}


TLSRecord *TLSRecordLayer::prepareTLSRecord(cPacket *appData) 
{    
    //------- TLS RECORD LAYER OPERATIONS ---------------//
        
    //1. Fragmentation:TODO Handle payload bigger than 2^14B:16KiB      
    ASSERT(appData->getByteLength() <= TLS_MAX_PLAINTEXT_LENGTH);
    
    //2. Compression:'CompressionMethod.null' is considered so, no compression is performed. Compressed Fragment no bigger than (2^14+1024)B
    
    
    TLSRecord *tlsRecord = new TLSRecord("TLS_Record");
    tlsRecord->setByteLength(TLS_HEADER);
    
    tlsRecord->setKind(appData->getKind());
    tlsRecord->setType(APPLICATION_DATA);

    tlsRecord->setVersion(version);

    cObject *controlInfo = appData->removeControlInfo();
    tlsRecord->setControlInfo(controlInfo);
    
    
    //3. Encryption
    //3.a Compute MAC-> default SHA_256 (32bits). 
   
    MAC *mac = new MAC("MAC");
    mac->setByteLength(32); //set the byteLength based on the mac_length defined in Security Parameters
    mac->setSeq_number(sequence_number);
    ++sequence_number;
    
    mac->encapsulate(appData);
   
    tlsRecord->encapsulate(mac);
    return tlsRecord;
}

cPacket *TLSRecordLayer::processTLSRecord(TLSRecord *tlsRecord) 
{
    if (tlsRecord->getType() == APPLICATION_DATA) {
        // 1. decrypt ...
        // 2. verify: retrieve MAC
        MAC *mac = check_and_cast <MAC*> (tlsRecord->decapsulate());
        uint64_t seq_num = mac->getSeq_number();
        if (seq_num == (sequence_number_prev + 1)) {
            // 3. decompress ..
            // 4. reassemble ..
            cPacket *appData = mac->decapsulate();
            appData->setKind(tlsRecord->getKind());
            cObject *controlInfo = tlsRecord->removeControlInfo();
            appData->setControlInfo(controlInfo);
        
            sequence_number_prev = seq_num;
            
            delete mac;
            delete tlsRecord;
            // 5. deliver       
            return appData;    
        }
        else {
            throw cRuntimeError("TLS Record Layer received data out of order.");
        } 
    }
    else {
        throw cRuntimeError("TLS Record Layer handles only Application Data.");
        delete tlsRecord;
    }
   
}

} //tls

} //inet
