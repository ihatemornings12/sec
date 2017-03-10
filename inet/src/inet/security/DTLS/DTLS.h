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


#ifndef __DTLS_H
#define __DTLS_H

#include "inet/common/INETDefs.h"

#include "inet/security/DTLS/recordLayer/DTLSRecordLayer.h"

namespace inet {

namespace dtls {

class DTLS: public cSimpleModule
{
    private:
        DTLSRecordLayer *recordLayer;

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        
        virtual void processMsgFromHigherLayer(cMessage *packet);
        virtual void processMsgFromLowerLayer(cMessage *packet);

    public:
        DTLS();
        ~DTLS();
};

} //dtls

} //inet

#endif
