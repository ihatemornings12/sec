//
// Generated file, do not edit! Created by nedtool 5.0 from inet/physicallayer/ieee80211/packetlevel/Ieee80211ControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Ieee80211ControlInfo_m.h"

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
namespace physicallayer {

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

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand() : ::inet::physicallayer::ConfigureRadioCommand()
{
    this->modeSet = nullptr;
    this->mode = nullptr;
    this->band = nullptr;
    this->channel = nullptr;
    this->channelNumber = -1;
}

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand(const Ieee80211ConfigureRadioCommand& other) : ::inet::physicallayer::ConfigureRadioCommand(other)
{
    copy(other);
}

Ieee80211ConfigureRadioCommand::~Ieee80211ConfigureRadioCommand()
{
}

Ieee80211ConfigureRadioCommand& Ieee80211ConfigureRadioCommand::operator=(const Ieee80211ConfigureRadioCommand& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::ConfigureRadioCommand::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ConfigureRadioCommand::copy(const Ieee80211ConfigureRadioCommand& other)
{
    this->opMode = other.opMode;
    this->modeSet = other.modeSet;
    this->mode = other.mode;
    this->band = other.band;
    this->channel = other.channel;
    this->channelNumber = other.channelNumber;
}

void Ieee80211ConfigureRadioCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::ConfigureRadioCommand&)*this);
    doParsimPacking(b,this->opMode);
    doParsimPacking(b,this->modeSet);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->band);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->channelNumber);
}

void Ieee80211ConfigureRadioCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::ConfigureRadioCommand&)*this);
    doParsimUnpacking(b,this->opMode);
    doParsimUnpacking(b,this->modeSet);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->band);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->channelNumber);
}

const char * Ieee80211ConfigureRadioCommand::getOpMode() const
{
    return this->opMode.c_str();
}

void Ieee80211ConfigureRadioCommand::setOpMode(const char * opMode)
{
    this->opMode = opMode;
}

Ieee80211ModeSetPtr& Ieee80211ConfigureRadioCommand::getModeSet()
{
    return this->modeSet;
}

void Ieee80211ConfigureRadioCommand::setModeSet(const Ieee80211ModeSetPtr& modeSet)
{
    this->modeSet = modeSet;
}

IIeee80211ModePtr& Ieee80211ConfigureRadioCommand::getMode()
{
    return this->mode;
}

void Ieee80211ConfigureRadioCommand::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

IIeee80211BandPtr& Ieee80211ConfigureRadioCommand::getBand()
{
    return this->band;
}

void Ieee80211ConfigureRadioCommand::setBand(const IIeee80211BandPtr& band)
{
    this->band = band;
}

Ieee80211ChannelPtr& Ieee80211ConfigureRadioCommand::getChannel()
{
    return this->channel;
}

void Ieee80211ConfigureRadioCommand::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

int Ieee80211ConfigureRadioCommand::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211ConfigureRadioCommand::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

class Ieee80211ConfigureRadioCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ConfigureRadioCommandDescriptor();
    virtual ~Ieee80211ConfigureRadioCommandDescriptor();

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

Register_ClassDescriptor(Ieee80211ConfigureRadioCommandDescriptor);

Ieee80211ConfigureRadioCommandDescriptor::Ieee80211ConfigureRadioCommandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211ConfigureRadioCommand", "inet::physicallayer::ConfigureRadioCommand")
{
    propertynames = nullptr;
}

Ieee80211ConfigureRadioCommandDescriptor::~Ieee80211ConfigureRadioCommandDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ConfigureRadioCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ConfigureRadioCommand *>(obj)!=nullptr;
}

const char **Ieee80211ConfigureRadioCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ConfigureRadioCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ieee80211ConfigureRadioCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "opMode",
        "modeSet",
        "mode",
        "band",
        "channel",
        "channelNumber",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int Ieee80211ConfigureRadioCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "opMode")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "modeSet")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mode")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "band")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelNumber")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Ieee80211ModeSetPtr",
        "IIeee80211ModePtr",
        "IIeee80211BandPtr",
        "Ieee80211ChannelPtr",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ConfigureRadioCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ConfigureRadioCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211ConfigureRadioCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getOpMode());
        case 1: {std::stringstream out; out << pp->getModeSet(); return out.str();}
        case 2: {std::stringstream out; out << pp->getMode(); return out.str();}
        case 3: {std::stringstream out; out << pp->getBand(); return out.str();}
        case 4: {std::stringstream out; out << pp->getChannel(); return out.str();}
        case 5: return long2string(pp->getChannelNumber());
        default: return "";
    }
}

bool Ieee80211ConfigureRadioCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setOpMode((value)); return true;
        case 5: pp->setChannelNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Ieee80211ModeSetPtr));
        case 2: return omnetpp::opp_typename(typeid(IIeee80211ModePtr));
        case 3: return omnetpp::opp_typename(typeid(IIeee80211BandPtr));
        case 4: return omnetpp::opp_typename(typeid(Ieee80211ChannelPtr));
        default: return nullptr;
    };
}

void *Ieee80211ConfigureRadioCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getModeSet()); break;
        case 2: return (void *)(&pp->getMode()); break;
        case 3: return (void *)(&pp->getBand()); break;
        case 4: return (void *)(&pp->getChannel()); break;
        default: return nullptr;
    }
}

Ieee80211TransmissionRequest::Ieee80211TransmissionRequest() : ::inet::physicallayer::TransmissionRequest()
{
    this->mode = nullptr;
    this->channelNumber = -1;
    this->channel = nullptr;
}

Ieee80211TransmissionRequest::Ieee80211TransmissionRequest(const Ieee80211TransmissionRequest& other) : ::inet::physicallayer::TransmissionRequest(other)
{
    copy(other);
}

Ieee80211TransmissionRequest::~Ieee80211TransmissionRequest()
{
}

Ieee80211TransmissionRequest& Ieee80211TransmissionRequest::operator=(const Ieee80211TransmissionRequest& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::TransmissionRequest::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211TransmissionRequest::copy(const Ieee80211TransmissionRequest& other)
{
    this->mode = other.mode;
    this->channelNumber = other.channelNumber;
    this->channel = other.channel;
}

void Ieee80211TransmissionRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::TransmissionRequest&)*this);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->channel);
}

void Ieee80211TransmissionRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::TransmissionRequest&)*this);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->channel);
}

IIeee80211ModePtr& Ieee80211TransmissionRequest::getMode()
{
    return this->mode;
}

void Ieee80211TransmissionRequest::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

int Ieee80211TransmissionRequest::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211TransmissionRequest::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

Ieee80211ChannelPtr& Ieee80211TransmissionRequest::getChannel()
{
    return this->channel;
}

void Ieee80211TransmissionRequest::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

class Ieee80211TransmissionRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211TransmissionRequestDescriptor();
    virtual ~Ieee80211TransmissionRequestDescriptor();

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

Register_ClassDescriptor(Ieee80211TransmissionRequestDescriptor);

Ieee80211TransmissionRequestDescriptor::Ieee80211TransmissionRequestDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211TransmissionRequest", "inet::physicallayer::TransmissionRequest")
{
    propertynames = nullptr;
}

Ieee80211TransmissionRequestDescriptor::~Ieee80211TransmissionRequestDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211TransmissionRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211TransmissionRequest *>(obj)!=nullptr;
}

const char **Ieee80211TransmissionRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211TransmissionRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211TransmissionRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211TransmissionRequestDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211TransmissionRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mode",
        "channelNumber",
        "channel",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211TransmissionRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mode")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelNumber")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211TransmissionRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IIeee80211ModePtr",
        "int",
        "Ieee80211ChannelPtr",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211TransmissionRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211TransmissionRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211TransmissionRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TransmissionRequest *pp = (Ieee80211TransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211TransmissionRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TransmissionRequest *pp = (Ieee80211TransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMode(); return out.str();}
        case 1: return long2string(pp->getChannelNumber());
        case 2: {std::stringstream out; out << pp->getChannel(); return out.str();}
        default: return "";
    }
}

bool Ieee80211TransmissionRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TransmissionRequest *pp = (Ieee80211TransmissionRequest *)object; (void)pp;
    switch (field) {
        case 1: pp->setChannelNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211TransmissionRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IIeee80211ModePtr));
        case 2: return omnetpp::opp_typename(typeid(Ieee80211ChannelPtr));
        default: return nullptr;
    };
}

void *Ieee80211TransmissionRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TransmissionRequest *pp = (Ieee80211TransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getMode()); break;
        case 2: return (void *)(&pp->getChannel()); break;
        default: return nullptr;
    }
}

Ieee80211ReceptionIndication::Ieee80211ReceptionIndication() : ::inet::physicallayer::ReceptionIndication()
{
    this->mode = nullptr;
    this->channel = nullptr;
    this->snr = 0;
    this->lossRate = 0;
    this->recPow = 0;
    this->airtimeMetric = false;
    this->testFrameDuration = 0;
    this->testFrameError = 0;
    this->testFrameSize = 0;
}

Ieee80211ReceptionIndication::Ieee80211ReceptionIndication(const Ieee80211ReceptionIndication& other) : ::inet::physicallayer::ReceptionIndication(other)
{
    copy(other);
}

Ieee80211ReceptionIndication::~Ieee80211ReceptionIndication()
{
}

Ieee80211ReceptionIndication& Ieee80211ReceptionIndication::operator=(const Ieee80211ReceptionIndication& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::ReceptionIndication::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReceptionIndication::copy(const Ieee80211ReceptionIndication& other)
{
    this->mode = other.mode;
    this->channel = other.channel;
    this->snr = other.snr;
    this->lossRate = other.lossRate;
    this->recPow = other.recPow;
    this->airtimeMetric = other.airtimeMetric;
    this->testFrameDuration = other.testFrameDuration;
    this->testFrameError = other.testFrameError;
    this->testFrameSize = other.testFrameSize;
}

void Ieee80211ReceptionIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::ReceptionIndication&)*this);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->snr);
    doParsimPacking(b,this->lossRate);
    doParsimPacking(b,this->recPow);
    doParsimPacking(b,this->airtimeMetric);
    doParsimPacking(b,this->testFrameDuration);
    doParsimPacking(b,this->testFrameError);
    doParsimPacking(b,this->testFrameSize);
}

void Ieee80211ReceptionIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::ReceptionIndication&)*this);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->snr);
    doParsimUnpacking(b,this->lossRate);
    doParsimUnpacking(b,this->recPow);
    doParsimUnpacking(b,this->airtimeMetric);
    doParsimUnpacking(b,this->testFrameDuration);
    doParsimUnpacking(b,this->testFrameError);
    doParsimUnpacking(b,this->testFrameSize);
}

IIeee80211ModePtr& Ieee80211ReceptionIndication::getMode()
{
    return this->mode;
}

void Ieee80211ReceptionIndication::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

Ieee80211ChannelPtr& Ieee80211ReceptionIndication::getChannel()
{
    return this->channel;
}

void Ieee80211ReceptionIndication::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

double Ieee80211ReceptionIndication::getSnr() const
{
    return this->snr;
}

void Ieee80211ReceptionIndication::setSnr(double snr)
{
    this->snr = snr;
}

double Ieee80211ReceptionIndication::getLossRate() const
{
    return this->lossRate;
}

void Ieee80211ReceptionIndication::setLossRate(double lossRate)
{
    this->lossRate = lossRate;
}

double Ieee80211ReceptionIndication::getRecPow() const
{
    return this->recPow;
}

void Ieee80211ReceptionIndication::setRecPow(double recPow)
{
    this->recPow = recPow;
}

bool Ieee80211ReceptionIndication::getAirtimeMetric() const
{
    return this->airtimeMetric;
}

void Ieee80211ReceptionIndication::setAirtimeMetric(bool airtimeMetric)
{
    this->airtimeMetric = airtimeMetric;
}

double Ieee80211ReceptionIndication::getTestFrameDuration() const
{
    return this->testFrameDuration;
}

void Ieee80211ReceptionIndication::setTestFrameDuration(double testFrameDuration)
{
    this->testFrameDuration = testFrameDuration;
}

double Ieee80211ReceptionIndication::getTestFrameError() const
{
    return this->testFrameError;
}

void Ieee80211ReceptionIndication::setTestFrameError(double testFrameError)
{
    this->testFrameError = testFrameError;
}

int Ieee80211ReceptionIndication::getTestFrameSize() const
{
    return this->testFrameSize;
}

void Ieee80211ReceptionIndication::setTestFrameSize(int testFrameSize)
{
    this->testFrameSize = testFrameSize;
}

class Ieee80211ReceptionIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ReceptionIndicationDescriptor();
    virtual ~Ieee80211ReceptionIndicationDescriptor();

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

Register_ClassDescriptor(Ieee80211ReceptionIndicationDescriptor);

Ieee80211ReceptionIndicationDescriptor::Ieee80211ReceptionIndicationDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211ReceptionIndication", "inet::physicallayer::ReceptionIndication")
{
    propertynames = nullptr;
}

Ieee80211ReceptionIndicationDescriptor::~Ieee80211ReceptionIndicationDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReceptionIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReceptionIndication *>(obj)!=nullptr;
}

const char **Ieee80211ReceptionIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReceptionIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReceptionIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211ReceptionIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ReceptionIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mode",
        "channel",
        "snr",
        "lossRate",
        "recPow",
        "airtimeMetric",
        "testFrameDuration",
        "testFrameError",
        "testFrameSize",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee80211ReceptionIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mode")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "snr")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "lossRate")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "recPow")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "airtimeMetric")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "testFrameDuration")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "testFrameError")==0) return base+7;
    if (fieldName[0]=='t' && strcmp(fieldName, "testFrameSize")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReceptionIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IIeee80211ModePtr",
        "Ieee80211ChannelPtr",
        "double",
        "double",
        "double",
        "bool",
        "double",
        "double",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ReceptionIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReceptionIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReceptionIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReceptionIndication *pp = (Ieee80211ReceptionIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee80211ReceptionIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReceptionIndication *pp = (Ieee80211ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMode(); return out.str();}
        case 1: {std::stringstream out; out << pp->getChannel(); return out.str();}
        case 2: return double2string(pp->getSnr());
        case 3: return double2string(pp->getLossRate());
        case 4: return double2string(pp->getRecPow());
        case 5: return bool2string(pp->getAirtimeMetric());
        case 6: return double2string(pp->getTestFrameDuration());
        case 7: return double2string(pp->getTestFrameError());
        case 8: return long2string(pp->getTestFrameSize());
        default: return "";
    }
}

bool Ieee80211ReceptionIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReceptionIndication *pp = (Ieee80211ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 2: pp->setSnr(string2double(value)); return true;
        case 3: pp->setLossRate(string2double(value)); return true;
        case 4: pp->setRecPow(string2double(value)); return true;
        case 5: pp->setAirtimeMetric(string2bool(value)); return true;
        case 6: pp->setTestFrameDuration(string2double(value)); return true;
        case 7: pp->setTestFrameError(string2double(value)); return true;
        case 8: pp->setTestFrameSize(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ReceptionIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IIeee80211ModePtr));
        case 1: return omnetpp::opp_typename(typeid(Ieee80211ChannelPtr));
        default: return nullptr;
    };
}

void *Ieee80211ReceptionIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReceptionIndication *pp = (Ieee80211ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getMode()); break;
        case 1: return (void *)(&pp->getChannel()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

