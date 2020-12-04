#ifndef MessageTypeMap_H
#define MessageTypeMap_H

#include "../core/preprocessors.h"
#include "../core/base_message.h"
#include <unordered_map>
#include <memory>

using namespace std;

DECLARE_SMART(BaseMsgCreatorInterface, spBaseMsgCreatorInterface);

class BaseMsgCreatorInterface
{
public:
    virtual spBaseMessageInterface createInst() = 0;
};

extern const unordered_map<const uint16_t, spBaseMsgCreatorInterface> MessageTypeMap;

#endif /* MessageTypeMap_H */
