#ifndef MessageTypeMap_H
#define MessageTypeMap_H

#include <map>
#include <memory>
#include <core/preprocessors.h>
#include <core/base_message.h>

using namespace std;

DECLARE_SMART(BaseMsgCreatorInterface, spBaseMsgCreatorInterface);

class BaseMsgCreatorInterface
{
public:
    virtual spBaseMessageInterface createInst() = 0;
};

#define MsgMapType map<const uint16_t, spBaseMsgCreatorInterface>

extern const MsgMapType MessageTypeMap;

#endif /* MessageTypeMap_H */
