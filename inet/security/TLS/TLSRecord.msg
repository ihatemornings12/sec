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
namespace tls {
}
}

}}

namespace inet::tls;

cplusplus {{ 
    #define TLS_HEADER  5   // TLS header length
    #define TLS_VERSION 3   // TLS v1.2
    #define TLS_MAX_PLAINTEXT_LENGTH 16384 //Max Fragment size, 2^14B
}}


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

packet TLSRecord
{
    //uint8_t headerLength = TLS_HEADER; 
    uint8_t type @enum(ContentType);
    ProtocolVersion version;
    uint16_t length; //max 2^14 bytes (16 KB)
}

// *********************************************************************************

//struct TLSPlaintext {
//    uint8_t type @enum(ContentType);
//    ProtocolVersion version = {3, 3}; 
//    uint16 length;
//    opaque fragment[TLSPlaintext.length];
//};

// ***********************************************************************************

//
//   
//struct TLSCompressed {
//    ContentType type;
//    ProtocolVersion ve--rsion;
//    uint16_t length; //increase no more than 1024 bytes -> 2^14+1024b
//    opaque fragment[TLSCompressed.length]; //TLSPlaintext.fragment
        //CompressionMethod.null
//};
    
//struct  TLSCiphertext {
//    ContentType type;
//    ProtocolVersion version;
//    uint16_t length;
    //select (SecurityParameters.cipher_type) {
    //    case stream: GenericStreamCipher;
    //    case block: GenericBlockCipher;
    //    case aead: GenericAEADCipher;
    //} fragment;
//};

//struct GenericStreamCipher {
    //  opaque content[TLSCompressed.length];
    //  opaque MAC[SecurityParameters.mac_length];
//};
    
//struct GenericBlockCipher {
    //    opaque IV[SecurityParameters.record_iv_length];
    //    block-ciphered struct {
    //      opaque content[TLSCompressed.length];
    //      opaque MAC[SecurityParameters.mac_length];
    //      uint8 padding[GenericBlockCipher.padding_length];
    //      uint8 padding_length;
    //    };
//};
    
//struct GenericAEADCipher {
    //    opaque nonce_explicit[SecurityParameters.record_iv_length];
    //    aead-ciphered struct {
    //        opaque content[TLSCompressed.length];
    //    };
//};
//

