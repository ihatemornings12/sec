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

  
cplusplus {{

#include "inet/common/INETDefs.h"

namespace inet {
namespace dtls {
}
}

}}
namespace inet::dtls;

cplusplus {{ 
    #define DTLS_HEADER  13   // TLS header length
    #define DTLS_VERSION_MAJOR 254   // DTLS v1.2
    #define DTLS_VERSION_MINOR 253
    #define DTLS_MAX_DATAGRAM 1500 //Max Fragment size, 2^14B
   // typedef std::array<unsigned char, 6> uint48_t;
}}

class noncobject uint48_t;

struct ProtocolVersion {
    uint8_t major;
    uint8_t minor;
};


enum ContentType {
    CHANGE_CIPHER_SPEC = 20; 
    ALERT = 21;
    HANDSHAKE = 22;
    APPLICATION_DATA = 23; 
};

// TLS Record Header
packet DTLSRecord
{
    uint8_t type @enum(ContentType);
    ProtocolVersion version;
    uint16_t epoch;     //A counter value that is incremented on every cipher state change. Init:0
    unsigned char sequence_number[6]; //The sequence number for this record. Init:0
    //uint64_t sequence_number;
    uint16_t length;    //max 2^14 bytes (16 KB): length of the payload
}

packet MAC
{
    //uint64_t seq_number;        // The sequence number used to compute the MAC is the 64-bit value 
                                // formed by concatenating the epoch and the sequence number
}
