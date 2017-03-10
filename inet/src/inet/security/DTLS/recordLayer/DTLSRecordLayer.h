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

#ifndef __DTLSRECORDLAYER_H
#define __DTLSRECORDLAYER_H

#include "inet/common/INETDefs.h"
#include "inet/security/DTLS/recordLayer/DTLSRecord_m.h"



// RFC 6347
// In order to ensure that any given sequence/epoch pair is unique,
// implementations MUST NOT allow the same epoch value to be reused
// within two times the TCP maximum segment lifetime.
//
// In general, implementations SHOULD discard packets from earlier epochs, 
// but if packet loss causes noticeable problems they MAY choose to retain
// keying material from previous epochs for up to the default MSL
// specified for TCP [TCP] to allow for packet reordering. (Note that
// the intention here is that implementors use the current guidance from
// the IETF for MSL,
//
// Until the handshake has completed, implementations MUST accept packets 
// from the old epoch.
//
// It is possible for records that are protected by the
// newly negotiated context to be received prior to the completion of a
// handshake. For instance, the server may send its Finished message
// and then start transmitting data. Implementations MAY either buffer
// or discard such packets, though when DTLS is used over reliable
// transports (e.g., SCTP), they SHOULD be buffered and processed once
// the handshake completes.

// Note that in the special case of a rehandshake on an existing
// association, it is safe to process a data packet immediately, even if
// the ChangeCipherSpec or Finished messages have not yet been received
// provided that either the rehandshake resumes the existing session or
// that it uses exactly the same security parameters as the existing
// association. In any other case, the implementation MUST wait for the
// receipt of the Finished message to prevent downgrade attack.
//
// As in TLS, implementations MUST either abandon an association or
// rehandshake prior to allowing the sequence number to wrap.
// Similarly, implementations MUST NOT allow the epoch to wrap, but
// instead MUST establish a new association, terminating the old
// association.

// Each DTLS record MUST fit within a single datagram. In order to
// avoid IP fragmentation, clients of the DTLS record layer SHOULD
// attempt to size records so that they fit within any PMTU estimates
// obtained from the record layer.
// The first byte of the datagram payload must be the beginning of a record.
//
// PMTU Issues:
// ============
// If PMTU estimates are available from the underlying transport
// protocol, they should be made available to upper layer protocols.
// In particular, for DTLS over UDP, the upper layer protocol SHOULD be 
// allowed to obtain the PMTU estimate maintained in the IP layer.
// If there is a transport protocol indication (e.g. ICMP indication),
// then the DTLS record layer MUST inform the upper layer protocol of the error. 
// The DTLS record layer SHOULD NOT interfere with upper layer protocols
// performing PMTU discovery, whether via [RFC1191] or [RFC4821] mechanisms.
// In particular:
// - Where allowed by the underlying transport protocol, the upper
// layer protocol SHOULD be allowed to set the state of the DF bit
// (in IPv4) or prohibit local fragmentation (in IPv6).
// - If the underlying transport protocol allows the application to
// request PMTU probing (e.g., DCCP), the DTLS record layer should
// honor this request.
//
// PMTU and DTLS Handshake:
// ========================
// - If the DTLS record layer informs the DTLS handshake layer that a
// message is too big, it SHOULD immediately attempt to fragment it,
// using any existing information about the PMTU.
// - If repeated retransmissions do not result in a response, and the
// PMTU is unknown, subsequent retransmissions SHOULD back off to a
// smaller record size, fragmenting the handshake message as
// appropriate. This standard does not specify an exact number of
// retransmits to attempt before backing off, but 2-3 seems appropriate.
//
// Anti-Reply:
// ===========
// DTLS records contain a sequence number to provide replay protection.
// Sequence number verification SHOULD be performed using the following
// sliding window procedure, borrowed from Section 3.4.3 of [ESP].
//
// The receiver packet counter for this session MUST be initialized to
// zero when the session is established. For each received record, the
// receiver MUST verify that the record contains a sequence number that
// does not duplicate the sequence number of any other record received
// during the life of this session. This SHOULD be the first check
// applied to a packet after it has been matched to a session, to speed
// rejection of duplicate records.
//
// Duplicates are rejected through the use of a sliding receive window.
// A minimum window size of 32 MUST be supported, but a window size of 
// 64 is preferred and SHOULD be employed as the default.
// The "right" edge of the window represents the highest validated
// sequence number value received on this session. Records that contain
// sequence numbers lower than the "left" edge of the window are
// rejected. Packets falling within the window are checked against a
// list of received packets within the window. An efficient means for
// performing this check, based on the use of a bit mask, is described
// in Section 3.4.3 of [ESP].
// 
// If the received record falls within the window and is new, or if the
// packet is to the right of the window, then the receiver proceeds to
// MAC verification. If the MAC validation fails, the receiver MUST
// discard the received record as invalid. The receive window is
// updated only if the MAC verification succeeds.
//


namespace inet{

using namespace std;

namespace dtls{

class DTLSRecordLayer 
{
private:
    uint16_t epoch;
    //uint48_t sequence_number;
    unsigned char sequence_number[6];
    uint64_t sequence_number_rcv;
    vector<uint64_t> sliding_window;
     
    ProtocolVersion version {};
    
    bool macVerification(DTLSRecord *dtlsRecord);
    cPacket *decapsulateAppPacket(DTLSRecord *dtlsRecord);
    void print(vector<uint64_t> sliding_window);
    
public:
    DTLSRecordLayer();
    virtual ~DTLSRecordLayer();
    
    DTLSRecord *prepareDTLSRecord(cPacket *appData);
    cPacket *processDTLSRecord(DTLSRecord *dtlsRecord);
        
};


} //dtls
} //inet

#endif 







