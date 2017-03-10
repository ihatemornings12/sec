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

cplusplus {{
 
#include "inet/common/INETDefs.h"

namespace inet {
namespace tls {
}
}

}}
namespace inet::tls;

enum ConnectionEnd 
{ 
    server = 0; 
    client = 1;
};

enum PRFAlgorithm
{ 
    tls_prf_sha256 = 0; 
};

enum BulkCipherAlgorithm 
{ 
    //null;
    //rc4, 
    //3des, 
    //aes 
};

enum CipherType
{   stream = 0;
    block = 1;
    aead = 2;
};

enum MACAlgorithm 
{ 
    //null;
    hmac_md5 = 1; 
    hmac_sha1 = 2; 
    hmac_sha256 = 3;
    hmac_sha384 = 4; 
    hmac_sha512 = 5;
};

enum CompressionMethod
{ 
    //null;
    //(255) 
};

class SecurityParameters
{
    uint8_t entity @enum(ConnectionEnd); 
    uint8_t prf_algorithm @enum(PRFAlgorithm);
    uint8_t bulk_cipher_algorithm @enum(BulkCipherAlgorithm);
    uint8_t cipher_type @enum(CipherType);
    uint8_t enc_key_length;
    uint8_t block_length;
    uint8_t fixed_iv_length;
    uint8_t record_iv_length;
    uint8_t mac_algorithm @enum(MACAlgorithm);
    uint8_t mac_length;
    uint8_t mac_key_length;
    uint8_t compression_algorithm @enum(CompressionMethod);
    uint8_t master_secret[48];
    uint8_t client_random[32];
    uint8_t server_random[32];
};

//Connection States MUST be updated for each record processed
message ConnectionState 
{
    // compression state: state of the compression algorithm -> none will be used
    // cipher state: state of the encryption algorithm
    // MAC key
    uint64_t sequence_num; //init to 0 when a connection state is made active. MAX (2^64-1). Do not wrap. If wrap->renegotiation. seq_num++ for each record
}


