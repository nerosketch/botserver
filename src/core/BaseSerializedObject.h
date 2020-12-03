//
// Created by ns on 7/20/20.
//

#ifndef BOTSERVER_BASESERIALIZEDOBJECT_H
#define BOTSERVER_BASESERIALIZEDOBJECT_H

#include <memory>
#include <iostream>

class BaseSerializedObject
{
private:
    unsigned int _uid;

public:
    BaseSerializedObject() : _uid(0){};
    BaseSerializedObject(const BaseSerializedObject &) = default;
    virtual ~BaseSerializedObject() = default;

    virtual void SerializeMe(std::istream &in) = 0;
    virtual void DeserializeMe(std::ostream &out) = 0;

    bool Save();
    bool Load();

    inline unsigned int getUid() const
    {
        return _uid;
    }
    inline void setUid(unsigned int uid)
    {
        _uid = uid;
    }
};

#endif //BOTSERVER_BASESERIALIZEDOBJECT_H
