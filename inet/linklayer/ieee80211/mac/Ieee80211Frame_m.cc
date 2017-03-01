//
// Generated file, do not edit! Created by nedtool 5.0 from inet/linklayer/ieee80211/mac/Ieee80211Frame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Ieee80211Frame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {
namespace ieee80211 {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211FrameType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211FrameType"));
    e->insert(ST_ASSOCIATIONREQUEST, "ST_ASSOCIATIONREQUEST");
    e->insert(ST_ASSOCIATIONRESPONSE, "ST_ASSOCIATIONRESPONSE");
    e->insert(ST_REASSOCIATIONREQUEST, "ST_REASSOCIATIONREQUEST");
    e->insert(ST_REASSOCIATIONRESPONSE, "ST_REASSOCIATIONRESPONSE");
    e->insert(ST_PROBEREQUEST, "ST_PROBEREQUEST");
    e->insert(ST_PROBERESPONSE, "ST_PROBERESPONSE");
    e->insert(ST_BEACON, "ST_BEACON");
    e->insert(ST_ATIM, "ST_ATIM");
    e->insert(ST_DISASSOCIATION, "ST_DISASSOCIATION");
    e->insert(ST_AUTHENTICATION, "ST_AUTHENTICATION");
    e->insert(ST_DEAUTHENTICATION, "ST_DEAUTHENTICATION");
    e->insert(ST_ACTION, "ST_ACTION");
    e->insert(ST_NOACKACTION, "ST_NOACKACTION");
    e->insert(ST_PSPOLL, "ST_PSPOLL");
    e->insert(ST_RTS, "ST_RTS");
    e->insert(ST_CTS, "ST_CTS");
    e->insert(ST_ACK, "ST_ACK");
    e->insert(ST_BLOCKACK_REQ, "ST_BLOCKACK_REQ");
    e->insert(ST_BLOCKACK, "ST_BLOCKACK");
    e->insert(ST_DATA, "ST_DATA");
    e->insert(ST_DATA_WITH_QOS, "ST_DATA_WITH_QOS");
    e->insert(ST_LBMS_REQUEST, "ST_LBMS_REQUEST");
    e->insert(ST_LBMS_REPORT, "ST_LBMS_REPORT");
);

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::AckPolicy");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::AckPolicy"));
    e->insert(NORMAL_ACK, "NORMAL_ACK");
    e->insert(NO_ACK, "NO_ACK");
    e->insert(NO_EXPLICIT_ACK, "NO_EXPLICIT_ACK");
    e->insert(BLOCK_ACK, "BLOCK_ACK");
);

Register_Class(Ieee80211Frame);

Ieee80211Frame::Ieee80211Frame(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->setByteLength(LENGTH_ACK / 8);

    this->type = 0;
    this->toDS = false;
    this->fromDS = false;
    this->retry = false;
    this->moreFragments = false;
    this->duration = -1;
    this->AID = -1;
    this->MACArrive = 0;
}

Ieee80211Frame::Ieee80211Frame(const Ieee80211Frame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

Ieee80211Frame::~Ieee80211Frame()
{
}

Ieee80211Frame& Ieee80211Frame::operator=(const Ieee80211Frame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211Frame::copy(const Ieee80211Frame& other)
{
    this->type = other.type;
    this->toDS = other.toDS;
    this->fromDS = other.fromDS;
    this->retry = other.retry;
    this->moreFragments = other.moreFragments;
    this->duration = other.duration;
    this->AID = other.AID;
    this->receiverAddress = other.receiverAddress;
    this->MACArrive = other.MACArrive;
}

void Ieee80211Frame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->toDS);
    doParsimPacking(b,this->fromDS);
    doParsimPacking(b,this->retry);
    doParsimPacking(b,this->moreFragments);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->AID);
    doParsimPacking(b,this->receiverAddress);
    doParsimPacking(b,this->MACArrive);
}

void Ieee80211Frame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->toDS);
    doParsimUnpacking(b,this->fromDS);
    doParsimUnpacking(b,this->retry);
    doParsimUnpacking(b,this->moreFragments);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->AID);
    doParsimUnpacking(b,this->receiverAddress);
    doParsimUnpacking(b,this->MACArrive);
}

short Ieee80211Frame::getType() const
{
    return this->type;
}

void Ieee80211Frame::setType(short type)
{
    this->type = type;
}

bool Ieee80211Frame::getToDS() const
{
    return this->toDS;
}

void Ieee80211Frame::setToDS(bool toDS)
{
    this->toDS = toDS;
}

bool Ieee80211Frame::getFromDS() const
{
    return this->fromDS;
}

void Ieee80211Frame::setFromDS(bool fromDS)
{
    this->fromDS = fromDS;
}

bool Ieee80211Frame::getRetry() const
{
    return this->retry;
}

void Ieee80211Frame::setRetry(bool retry)
{
    this->retry = retry;
}

bool Ieee80211Frame::getMoreFragments() const
{
    return this->moreFragments;
}

void Ieee80211Frame::setMoreFragments(bool moreFragments)
{
    this->moreFragments = moreFragments;
}

::omnetpp::simtime_t Ieee80211Frame::getDuration() const
{
    return this->duration;
}

void Ieee80211Frame::setDuration(::omnetpp::simtime_t duration)
{
    this->duration = duration;
}

short Ieee80211Frame::getAID() const
{
    return this->AID;
}

void Ieee80211Frame::setAID(short AID)
{
    this->AID = AID;
}

MACAddress& Ieee80211Frame::getReceiverAddress()
{
    return this->receiverAddress;
}

void Ieee80211Frame::setReceiverAddress(const MACAddress& receiverAddress)
{
    this->receiverAddress = receiverAddress;
}

::omnetpp::simtime_t Ieee80211Frame::getMACArrive() const
{
    return this->MACArrive;
}

void Ieee80211Frame::setMACArrive(::omnetpp::simtime_t MACArrive)
{
    this->MACArrive = MACArrive;
}

class Ieee80211FrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211FrameDescriptor();
    virtual ~Ieee80211FrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211FrameDescriptor);

Ieee80211FrameDescriptor::Ieee80211FrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211Frame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

Ieee80211FrameDescriptor::~Ieee80211FrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211FrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211Frame *>(obj)!=nullptr;
}

const char **Ieee80211FrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211FrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211FrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211FrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211FrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "toDS",
        "fromDS",
        "retry",
        "moreFragments",
        "duration",
        "AID",
        "receiverAddress",
        "MACArrive",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee80211FrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "toDS")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromDS")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "retry")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "moreFragments")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+5;
    if (fieldName[0]=='A' && strcmp(fieldName, "AID")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverAddress")==0) return base+7;
    if (fieldName[0]=='M' && strcmp(fieldName, "MACArrive")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211FrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "bool",
        "bool",
        "bool",
        "bool",
        "simtime_t",
        "short",
        "MACAddress",
        "simtime_t",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211FrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211FrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211FrameType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211FrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211FrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::ieee80211::Ieee80211FrameType");
        case 1: return bool2string(pp->getToDS());
        case 2: return bool2string(pp->getFromDS());
        case 3: return bool2string(pp->getRetry());
        case 4: return bool2string(pp->getMoreFragments());
        case 5: return simtime2string(pp->getDuration());
        case 6: return long2string(pp->getAID());
        case 7: {std::stringstream out; out << pp->getReceiverAddress(); return out.str();}
        case 8: return simtime2string(pp->getMACArrive());
        default: return "";
    }
}

bool Ieee80211FrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::ieee80211::Ieee80211FrameType)string2enum(value, "inet::ieee80211::Ieee80211FrameType")); return true;
        case 1: pp->setToDS(string2bool(value)); return true;
        case 2: pp->setFromDS(string2bool(value)); return true;
        case 3: pp->setRetry(string2bool(value)); return true;
        case 4: pp->setMoreFragments(string2bool(value)); return true;
        case 5: pp->setDuration(string2simtime(value)); return true;
        case 6: pp->setAID(string2long(value)); return true;
        case 8: pp->setMACArrive(string2simtime(value)); return true;
        default: return false;
    }
}

const char *Ieee80211FrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211FrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getReceiverAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211OneAddressFrame);

Ieee80211OneAddressFrame::Ieee80211OneAddressFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211Frame(name,kind)
{
}

Ieee80211OneAddressFrame::Ieee80211OneAddressFrame(const Ieee80211OneAddressFrame& other) : ::inet::ieee80211::Ieee80211Frame(other)
{
    copy(other);
}

Ieee80211OneAddressFrame::~Ieee80211OneAddressFrame()
{
}

Ieee80211OneAddressFrame& Ieee80211OneAddressFrame::operator=(const Ieee80211OneAddressFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211Frame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211OneAddressFrame::copy(const Ieee80211OneAddressFrame& other)
{
}

void Ieee80211OneAddressFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211Frame::parsimPack(b);
}

void Ieee80211OneAddressFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211Frame::parsimUnpack(b);
}

class Ieee80211OneAddressFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211OneAddressFrameDescriptor();
    virtual ~Ieee80211OneAddressFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211OneAddressFrameDescriptor);

Ieee80211OneAddressFrameDescriptor::Ieee80211OneAddressFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211OneAddressFrame", "inet::ieee80211::Ieee80211Frame")
{
    propertynames = nullptr;
}

Ieee80211OneAddressFrameDescriptor::~Ieee80211OneAddressFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OneAddressFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OneAddressFrame *>(obj)!=nullptr;
}

const char **Ieee80211OneAddressFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OneAddressFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OneAddressFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211OneAddressFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211OneAddressFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211OneAddressFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211OneAddressFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211OneAddressFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211OneAddressFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211OneAddressFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ACKFrame);

Ieee80211ACKFrame::Ieee80211ACKFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_ACK / 8);
    this->setType(ST_ACK);
}

Ieee80211ACKFrame::Ieee80211ACKFrame(const Ieee80211ACKFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211ACKFrame::~Ieee80211ACKFrame()
{
}

Ieee80211ACKFrame& Ieee80211ACKFrame::operator=(const Ieee80211ACKFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ACKFrame::copy(const Ieee80211ACKFrame& other)
{
}

void Ieee80211ACKFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
}

void Ieee80211ACKFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
}

class Ieee80211ACKFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ACKFrameDescriptor();
    virtual ~Ieee80211ACKFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211ACKFrameDescriptor);

Ieee80211ACKFrameDescriptor::Ieee80211ACKFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ACKFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211ACKFrameDescriptor::~Ieee80211ACKFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ACKFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ACKFrame *>(obj)!=nullptr;
}

const char **Ieee80211ACKFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ACKFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ACKFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ACKFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ACKFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ACKFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ACKFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ACKFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211ACKFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211ACKFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211ACKFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ACKFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ACKFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ACKFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211TwoAddressFrame);

Ieee80211TwoAddressFrame::Ieee80211TwoAddressFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_RTS / 8);

}

Ieee80211TwoAddressFrame::Ieee80211TwoAddressFrame(const Ieee80211TwoAddressFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211TwoAddressFrame::~Ieee80211TwoAddressFrame()
{
}

Ieee80211TwoAddressFrame& Ieee80211TwoAddressFrame::operator=(const Ieee80211TwoAddressFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211TwoAddressFrame::copy(const Ieee80211TwoAddressFrame& other)
{
    this->transmitterAddress = other.transmitterAddress;
}

void Ieee80211TwoAddressFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
    doParsimPacking(b,this->transmitterAddress);
}

void Ieee80211TwoAddressFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->transmitterAddress);
}

MACAddress& Ieee80211TwoAddressFrame::getTransmitterAddress()
{
    return this->transmitterAddress;
}

void Ieee80211TwoAddressFrame::setTransmitterAddress(const MACAddress& transmitterAddress)
{
    this->transmitterAddress = transmitterAddress;
}

class Ieee80211TwoAddressFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211TwoAddressFrameDescriptor();
    virtual ~Ieee80211TwoAddressFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211TwoAddressFrameDescriptor);

Ieee80211TwoAddressFrameDescriptor::Ieee80211TwoAddressFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211TwoAddressFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211TwoAddressFrameDescriptor::~Ieee80211TwoAddressFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211TwoAddressFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211TwoAddressFrame *>(obj)!=nullptr;
}

const char **Ieee80211TwoAddressFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211TwoAddressFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211TwoAddressFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211TwoAddressFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transmitterAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211TwoAddressFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transmitterAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211TwoAddressFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211TwoAddressFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211TwoAddressFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTransmitterAddress(); return out.str();}
        default: return "";
    }
}

bool Ieee80211TwoAddressFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211TwoAddressFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTransmitterAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211RTSFrame);

Ieee80211RTSFrame::Ieee80211RTSFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_RTS / 8);
    this->setType(ST_RTS);
}

Ieee80211RTSFrame::Ieee80211RTSFrame(const Ieee80211RTSFrame& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211RTSFrame::~Ieee80211RTSFrame()
{
}

Ieee80211RTSFrame& Ieee80211RTSFrame::operator=(const Ieee80211RTSFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211RTSFrame::copy(const Ieee80211RTSFrame& other)
{
}

void Ieee80211RTSFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
}

void Ieee80211RTSFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
}

class Ieee80211RTSFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211RTSFrameDescriptor();
    virtual ~Ieee80211RTSFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211RTSFrameDescriptor);

Ieee80211RTSFrameDescriptor::Ieee80211RTSFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211RTSFrame", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211RTSFrameDescriptor::~Ieee80211RTSFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211RTSFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211RTSFrame *>(obj)!=nullptr;
}

const char **Ieee80211RTSFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211RTSFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211RTSFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211RTSFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211RTSFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211RTSFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211RTSFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211RTSFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211RTSFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211RTSFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211RTSFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211RTSFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211RTSFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211RTSFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211CTSFrame);

Ieee80211CTSFrame::Ieee80211CTSFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_CTS / 8);
    this->setType(ST_CTS);
}

Ieee80211CTSFrame::Ieee80211CTSFrame(const Ieee80211CTSFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211CTSFrame::~Ieee80211CTSFrame()
{
}

Ieee80211CTSFrame& Ieee80211CTSFrame::operator=(const Ieee80211CTSFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CTSFrame::copy(const Ieee80211CTSFrame& other)
{
}

void Ieee80211CTSFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
}

void Ieee80211CTSFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
}

class Ieee80211CTSFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211CTSFrameDescriptor();
    virtual ~Ieee80211CTSFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211CTSFrameDescriptor);

Ieee80211CTSFrameDescriptor::Ieee80211CTSFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211CTSFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211CTSFrameDescriptor::~Ieee80211CTSFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CTSFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CTSFrame *>(obj)!=nullptr;
}

const char **Ieee80211CTSFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CTSFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CTSFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211CTSFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211CTSFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211CTSFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CTSFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211CTSFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211CTSFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211CTSFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211CTSFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211CTSFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211CTSFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211CTSFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataOrMgmtFrame);

Ieee80211DataOrMgmtFrame::Ieee80211DataOrMgmtFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_MGMT / 8);

    this->fragmentNumber = 0;
    this->sequenceNumber = 0;
}

Ieee80211DataOrMgmtFrame::Ieee80211DataOrMgmtFrame(const Ieee80211DataOrMgmtFrame& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211DataOrMgmtFrame::~Ieee80211DataOrMgmtFrame()
{
}

Ieee80211DataOrMgmtFrame& Ieee80211DataOrMgmtFrame::operator=(const Ieee80211DataOrMgmtFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataOrMgmtFrame::copy(const Ieee80211DataOrMgmtFrame& other)
{
    this->address3 = other.address3;
    this->fragmentNumber = other.fragmentNumber;
    this->sequenceNumber = other.sequenceNumber;
}

void Ieee80211DataOrMgmtFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
    doParsimPacking(b,this->address3);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->sequenceNumber);
}

void Ieee80211DataOrMgmtFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->address3);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->sequenceNumber);
}

MACAddress& Ieee80211DataOrMgmtFrame::getAddress3()
{
    return this->address3;
}

void Ieee80211DataOrMgmtFrame::setAddress3(const MACAddress& address3)
{
    this->address3 = address3;
}

short Ieee80211DataOrMgmtFrame::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211DataOrMgmtFrame::setFragmentNumber(short fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

uint16_t Ieee80211DataOrMgmtFrame::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Ieee80211DataOrMgmtFrame::setSequenceNumber(uint16_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

class Ieee80211DataOrMgmtFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataOrMgmtFrameDescriptor();
    virtual ~Ieee80211DataOrMgmtFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211DataOrMgmtFrameDescriptor);

Ieee80211DataOrMgmtFrameDescriptor::Ieee80211DataOrMgmtFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataOrMgmtFrame", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211DataOrMgmtFrameDescriptor::~Ieee80211DataOrMgmtFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataOrMgmtFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataOrMgmtFrame *>(obj)!=nullptr;
}

const char **Ieee80211DataOrMgmtFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataOrMgmtFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211DataOrMgmtFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address3",
        "fragmentNumber",
        "sequenceNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211DataOrMgmtFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address3")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "short",
        "uint16",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataOrMgmtFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211DataOrMgmtFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211DataOrMgmtFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddress3(); return out.str();}
        case 1: return long2string(pp->getFragmentNumber());
        case 2: return ulong2string(pp->getSequenceNumber());
        default: return "";
    }
}

bool Ieee80211DataOrMgmtFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 1: pp->setFragmentNumber(string2long(value)); return true;
        case 2: pp->setSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211DataOrMgmtFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddress3()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataFrame);

Ieee80211DataFrame::Ieee80211DataFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(name,kind)
{
    this->setByteLength(DATAFRAME_HEADER_MINLENGTH / 8);
    this->setType(ST_DATA);

    this->qos = 0;
    this->ackPolicy = 0;
    this->tid = 0;
}

Ieee80211DataFrame::Ieee80211DataFrame(const Ieee80211DataFrame& other) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(other)
{
    copy(other);
}

Ieee80211DataFrame::~Ieee80211DataFrame()
{
}

Ieee80211DataFrame& Ieee80211DataFrame::operator=(const Ieee80211DataFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataFrame::copy(const Ieee80211DataFrame& other)
{
    this->address4 = other.address4;
    this->qos = other.qos;
    this->ackPolicy = other.ackPolicy;
    this->tid = other.tid;
}

void Ieee80211DataFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimPack(b);
    doParsimPacking(b,this->address4);
    doParsimPacking(b,this->qos);
    doParsimPacking(b,this->ackPolicy);
    doParsimPacking(b,this->tid);
}

void Ieee80211DataFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->address4);
    doParsimUnpacking(b,this->qos);
    doParsimUnpacking(b,this->ackPolicy);
    doParsimUnpacking(b,this->tid);
}

MACAddress& Ieee80211DataFrame::getAddress4()
{
    return this->address4;
}

void Ieee80211DataFrame::setAddress4(const MACAddress& address4)
{
    this->address4 = address4;
}

uint16_t Ieee80211DataFrame::getQos() const
{
    return this->qos;
}

void Ieee80211DataFrame::setQos(uint16_t qos)
{
    this->qos = qos;
}

int Ieee80211DataFrame::getAckPolicy() const
{
    return this->ackPolicy;
}

void Ieee80211DataFrame::setAckPolicy(int ackPolicy)
{
    this->ackPolicy = ackPolicy;
}

uint8_t Ieee80211DataFrame::getTid() const
{
    return this->tid;
}

void Ieee80211DataFrame::setTid(uint8_t tid)
{
    this->tid = tid;
}

class Ieee80211DataFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataFrameDescriptor();
    virtual ~Ieee80211DataFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211DataFrameDescriptor);

Ieee80211DataFrameDescriptor::Ieee80211DataFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataFrame", "inet::ieee80211::Ieee80211DataOrMgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211DataFrameDescriptor::~Ieee80211DataFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataFrame *>(obj)!=nullptr;
}

const char **Ieee80211DataFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211DataFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address4",
        "qos",
        "ackPolicy",
        "tid",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211DataFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address4")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackPolicy")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tid")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "uint16",
        "int",
        "uint8",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DataFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::AckPolicy";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DataFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211DataFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddress4(); return out.str();}
        case 1: return ulong2string(pp->getQos());
        case 2: return enum2string(pp->getAckPolicy(), "inet::ieee80211::AckPolicy");
        case 3: return ulong2string(pp->getTid());
        default: return "";
    }
}

bool Ieee80211DataFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 1: pp->setQos(string2ulong(value)); return true;
        case 2: pp->setAckPolicy((inet::ieee80211::AckPolicy)string2enum(value, "inet::ieee80211::AckPolicy")); return true;
        case 3: pp->setTid(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211DataFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddress4()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataFrameWithSNAP);

Ieee80211DataFrameWithSNAP::Ieee80211DataFrameWithSNAP(const char *name, int kind) : ::inet::ieee80211::Ieee80211DataFrame(name,kind)
{
    this->setByteLength(DATAFRAME_HEADER_MINLENGTH / 8 + SNAP_HEADER_BYTES);

    this->etherType = 0;
}

Ieee80211DataFrameWithSNAP::Ieee80211DataFrameWithSNAP(const Ieee80211DataFrameWithSNAP& other) : ::inet::ieee80211::Ieee80211DataFrame(other)
{
    copy(other);
}

Ieee80211DataFrameWithSNAP::~Ieee80211DataFrameWithSNAP()
{
}

Ieee80211DataFrameWithSNAP& Ieee80211DataFrameWithSNAP::operator=(const Ieee80211DataFrameWithSNAP& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataFrameWithSNAP::copy(const Ieee80211DataFrameWithSNAP& other)
{
    this->etherType = other.etherType;
}

void Ieee80211DataFrameWithSNAP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataFrame::parsimPack(b);
    doParsimPacking(b,this->etherType);
}

void Ieee80211DataFrameWithSNAP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->etherType);
}

int Ieee80211DataFrameWithSNAP::getEtherType() const
{
    return this->etherType;
}

void Ieee80211DataFrameWithSNAP::setEtherType(int etherType)
{
    this->etherType = etherType;
}

class Ieee80211DataFrameWithSNAPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataFrameWithSNAPDescriptor();
    virtual ~Ieee80211DataFrameWithSNAPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211DataFrameWithSNAPDescriptor);

Ieee80211DataFrameWithSNAPDescriptor::Ieee80211DataFrameWithSNAPDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataFrameWithSNAP", "inet::ieee80211::Ieee80211DataFrame")
{
    propertynames = nullptr;
}

Ieee80211DataFrameWithSNAPDescriptor::~Ieee80211DataFrameWithSNAPDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataFrameWithSNAPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataFrameWithSNAP *>(obj)!=nullptr;
}

const char **Ieee80211DataFrameWithSNAPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataFrameWithSNAPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DataFrameWithSNAPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "etherType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DataFrameWithSNAPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataFrameWithSNAPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "EtherType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DataFrameWithSNAPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211DataFrameWithSNAPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getEtherType(), "EtherType");
        default: return "";
    }
}

bool Ieee80211DataFrameWithSNAPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: pp->setEtherType((EtherType)string2enum(value, "EtherType")); return true;
        default: return false;
    }
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ieee80211DataFrameWithSNAPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ManagementFrame);

Ieee80211ManagementFrame::Ieee80211ManagementFrame(const char *name, int kind) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(name,kind)
{
    this->Category = 0;
}

Ieee80211ManagementFrame::Ieee80211ManagementFrame(const Ieee80211ManagementFrame& other) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(other)
{
    copy(other);
}

Ieee80211ManagementFrame::~Ieee80211ManagementFrame()
{
}

Ieee80211ManagementFrame& Ieee80211ManagementFrame::operator=(const Ieee80211ManagementFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ManagementFrame::copy(const Ieee80211ManagementFrame& other)
{
    this->Category = other.Category;
}

void Ieee80211ManagementFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimPack(b);
    doParsimPacking(b,this->Category);
}

void Ieee80211ManagementFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->Category);
}

short Ieee80211ManagementFrame::getCategory() const
{
    return this->Category;
}

void Ieee80211ManagementFrame::setCategory(short Category)
{
    this->Category = Category;
}

class Ieee80211ManagementFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ManagementFrameDescriptor();
    virtual ~Ieee80211ManagementFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ieee80211ManagementFrameDescriptor);

Ieee80211ManagementFrameDescriptor::Ieee80211ManagementFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ManagementFrame", "inet::ieee80211::Ieee80211DataOrMgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211ManagementFrameDescriptor::~Ieee80211ManagementFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ManagementFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ManagementFrame *>(obj)!=nullptr;
}

const char **Ieee80211ManagementFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ManagementFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ManagementFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ManagementFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ManagementFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Category",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ManagementFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='C' && strcmp(fieldName, "Category")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ManagementFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ManagementFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ieee80211ManagementFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ieee80211ManagementFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211ManagementFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCategory());
        default: return "";
    }
}

bool Ieee80211ManagementFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setCategory(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ManagementFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ieee80211ManagementFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace ieee80211
} // namespace inet

