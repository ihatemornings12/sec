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
//

#include <algorithm>

#include "DTLSRecordLayer.h"
#include "inet/transportlayer/contract/udp/UDPControlInfo.h"
#include "inet/applications/tcpapp/GenericAppMsg_m.h"


namespace inet {

namespace dtls {

DTLSRecordLayer::DTLSRecordLayer()
{
    epoch = 0;
    for (unsigned int  i = 0; i < 6; i++)
            sequence_number[i] = 0x00;
            
    sequence_number_rcv = 0; //The receiver packet counter for this session MUST be initialized to zero when the session is established.
    sliding_window.push_back(sequence_number_rcv);
    version.major = DTLS_VERSION_MAJOR;
    version.minor = DTLS_VERSION_MINOR;
}

DTLSRecordLayer::~DTLSRecordLayer()
{
}


DTLSRecord *DTLSRecordLayer::prepareDTLSRecord(cPacket *appData) 
{    
    //------- DTLS RECORD LAYER OPERATIONS ---------------//
        
    //1. Each record should fit in a datagram without fragmentation
    //TODO:handle discovery PMTU    
    ASSERT(appData->getByteLength() < DTLS_MAX_DATAGRAM);
        
    DTLSRecord *dtlsRecord = new DTLSRecord("DTLS_Record");
    dtlsRecord->setByteLength(DTLS_HEADER);
    dtlsRecord->setVersion(version);
    dtlsRecord->setType(APPLICATION_DATA);
    dtlsRecord->setKind(appData->getKind());
   
    dtlsRecord->setEpoch(epoch);
    for (auto i = 0; i < 6; i++)
        dtlsRecord->setSequence_number(i, sequence_number[i]);
        
    //retrieve the number
    uint64_t seq_num = *(uint64_t *)sequence_number; 
    //increase the seq_num   
    seq_num = seq_num + 1;
    
    //store it back to the array
    sequence_number[0] = seq_num & 0xff; //lower byte    
    sequence_number[1] = (seq_num >> 8) & 0xff;
    sequence_number[2] = (seq_num >> 16) & 0xff;    
    sequence_number[3] = (seq_num >> 24) & 0xff;    
    sequence_number[4] = (seq_num >> 32) & 0xff;    
    sequence_number[5] = (seq_num >> 40) & 0xff;
    
    cObject *controlInfo = (appData->removeControlInfo());
    dtlsRecord->setControlInfo(controlInfo);
        
    //2. Encryption
    //2.a Compute MAC-> default SHA_256 (32bits). 
    //theoretical consideration that MAC is calculated using the concatination of epoch and seq_numb
    MAC *mac = new MAC("MAC"); 
    mac->setByteLength(32); //set the byteLength based on the mac_length defined in Security Parameters
   
    mac->encapsulate(appData);
     
    dtlsRecord->encapsulate(mac);
    return dtlsRecord;
}

cPacket *DTLSRecordLayer::processDTLSRecord(DTLSRecord *dtlsRecord) 
{
    cPacket *appData = NULL;
    if (dtlsRecord->getType() == APPLICATION_DATA) {
        //Anti-Reply protection:   

        unsigned char seq_num[6];       
        unsigned int length = dtlsRecord->getSequence_numberArraySize();        
        for (unsigned int  i = 0; i < length; i++)
            seq_num[i] = dtlsRecord->getSequence_number(i);
        uint64_t snumber = *(uint64_t *)seq_num;   

        // The first packet MUST has seq_num = 0        
        if (snumber == sequence_number_rcv) {
            if (macVerification(dtlsRecord))
                appData = decapsulateAppPacket(dtlsRecord);
            else 
                delete dtlsRecord;  
        }
        else { 
            //1. Check for duplicate
            if (find(sliding_window.begin(), sliding_window.end(), snumber) != sliding_window.end())
                delete dtlsRecord;
             //2. Records that contain sequence numbers lower than the "left" edge of the window are rejected
            else if (snumber < sliding_window.front())
                delete dtlsRecord;
            //3. The "right" edge of the window represents the highest validated sequence number value received
            else if (snumber > sliding_window.back()) {
                if (macVerification(dtlsRecord)) {
                    sliding_window.push_back(snumber);
                    appData = decapsulateAppPacket(dtlsRecord);
                }
                else 
                    delete dtlsRecord;
            }
            //4. Packet falls within the window
            else {
                //a. Insert elements in a sorted order and check for duplicates
                vector<uint64_t>::iterator i = sliding_window.begin();
                while (i != (sliding_window.end() - 1)) {
                    if ((snumber > *i) && (snumber < *(i+1))) {
                        if (macVerification(dtlsRecord)) {
                            //b. Update the sliding window after the successful MAC validation
                            sliding_window.insert(i+1, snumber);
                            //print(sliding_window);
                            appData = decapsulateAppPacket(dtlsRecord); 
                            break;
                        }                  
                        else 
                            delete dtlsRecord;
                    }
                    ++i;
                }
            }
        }
        //==============================================================
        
     /*  gia uint64_t        
        //uint64_t seq_num = dtlsRecord->getSequence_number();
       
        if (seq_num == sequence_number_rcv) { //First packet must be 0
            EV << "First record of the session is received\n";
            if(macVerification(dtlsRecord))
                appData = decapsulateAppPacket(dtlsRecord);
            else 
                delete dtlsRecord;  
        }        
        else { 
            //1. Check for duplicate
            if (find(sliding_window.begin(), sliding_window.end(), seq_num) != sliding_window.end())
                delete dtlsRecord;
            
            //2. Records that contain sequence numbers lower than the "left" edge of the window are rejected
            else if (seq_num < sliding_window.front())
                delete dtlsRecord;
            
            //3. The "right" edge of the window represents the highest validated sequence number value received
            else if (seq_num > sliding_window.back()) {
                if (macVerification(dtlsRecord)) {
                    sliding_window.push_back(seq_num);
                    appData = decapsulateAppPacket(dtlsRecord);
                }
                else 
                    delete dtlsRecord;
            }
            //4. Packet falls within the window
            else {
                //a. Insert elements in a sorted order and check for duplicates
                vector<uint64_t>::iterator i = sliding_window.begin();
                while (i != (sliding_window.end() - 1)) {
                    if ((seq_num > *i) && (seq_num < *(i+1))) {
                        if (macVerification(dtlsRecord)) {
                            //b. Update the sliding window after the successful MAC validation
                            sliding_window.insert(i+1, seq_num);
                            //print(sliding_window);
                            appData = decapsulateAppPacket(dtlsRecord); 
                            break;
                        }                  
                        else 
                            delete dtlsRecord;
                    }
                    ++i;
                }
            }
        }*/
        return appData;
    }
    else {
        throw cRuntimeError("DTLS Record Layer handles only Application Data.");
        delete dtlsRecord;
    }
   
}

void DTLSRecordLayer::print(vector<uint64_t> sliding_window)
{
    vector<uint64_t>::iterator i = sliding_window.begin();
    while (i != sliding_window.end()) {
        cout << " " << *i ;
        ++i;
    }
    cout << endl;

}

cPacket *DTLSRecordLayer::decapsulateAppPacket(DTLSRecord *dtlsRecord)
{
    MAC *mac = check_and_cast <MAC*> (dtlsRecord->decapsulate());
    cPacket *appData = mac->decapsulate();
    appData->setKind(dtlsRecord->getKind());
    cObject *controlInfo = dtlsRecord->removeControlInfo(); 
    appData->setControlInfo(controlInfo);
    
    delete mac;
    delete dtlsRecord;
    
    return appData;
    
}

bool DTLSRecordLayer::macVerification(DTLSRecord *dtlsRecord)
{
    if (check_and_cast <MAC*> (dtlsRecord->getEncapsulatedPacket()))
        return true;
    return false;

}

} //tls

} //inet
