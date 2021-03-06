#ifndef MessageTypeMap_H
#define MessageTypeMap_H

#include <map>
#include <memory>
#include <core/core.h>

using namespace std;
using namespace botserver;

DECLARE_SMART(BaseMsgCreatorInterface, spBaseMsgCreatorInterface);

class BaseMsgCreatorInterface
{
public:
    virtual spBaseMessageInterface createInst() = 0;
};

#define MsgMapType map<const uint16_t, spBaseMsgCreatorInterface>

extern const MsgMapType MessageTypeMap;

#endif /* MessageTypeMap_H */
