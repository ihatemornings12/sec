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

#ifndef __TLSRECORDLAYER_H
#define __TLSRECORDLAYER_H

#include "inet/common/INETDefs.h"
#include "inet/security/TLS/TLSRecord_m.h"

//
// The TLS Record Protocol is a layered protocol. At each layer,
// messages may include fields for length, description, and content.
// The Record Protocol takes messages to be transmitted, fragments the
// data into manageable blocks, optionally compresses the data, applies
// a MAC, encrypts, and transmits the result. Received data is
// decrypted, verified, decompressed, reassembled, and then delivered to
// higher-level clients.
// 

namespace inet{

namespace tls{

class TLSRecord;

class TLSRecordLayer 
{
public:
    TLSRecordLayer();
    virtual ~TLSRecordLayer();
    
    TLSRecord *prepareTLSRecord(cPacket *appData);
    cPacket *processTLSRecord(TLSRecord *tlsRecord);
        
};


}
}
#endif 
