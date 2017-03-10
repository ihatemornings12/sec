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


package inet.security.DTLS;

// The protocol is composed of two layers: the TLS Record Protocol and the
// TLS Handshake Protocol.
// At the lowest level, layered on top of some reliable transport protocol 
// (e.g., TCP [TCP]), is the TLS Record Protocol.
//
// The TLS Record Protocol is used for encapsulation of various higher-
// level protocols. One such encapsulated protocol, the TLS Handshake
// Protocol, allows the server and client to authenticate each other and
// to negotiate an encryption algorithm and cryptographic keys before
// the application protocol transmits or receives its first byte of
// data.
//
// The Record Protocol takes messages to be transmitted, fragments the
// data into manageable blocks, optionally compresses the data, applies
// a MAC, encrypts, and transmits the result. Received data is
// decrypted, verified, decompressed, reassembled, and then delivered to
// higher-level clients.
// Four protocols that use the record protocol are described in this
// document: the handshake protocol, the alert protocol, the change
// cipher spec protocol, and the application data protocol.

simple DTLS 
{
    parameters:
        @display("i=block/wheelbarrow");
    gates:
        input dtls_appIn[];
        output dtls_appOut[];
        
        input dtls_udpIn[];
        output dtls_udpOut[];
}
