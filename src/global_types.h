/*
 * File:   global_types.h
 * Author: ns
 *
 * Created on June 30, 2020, 12:14 AM
 */

#ifndef GLOBAL_TYPES_H
#define GLOBAL_TYPES_H

//#include <cstdint>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> RequestParamsMap;

class Color
{
public:
    Color();

    Color(const Color &o);

    virtual ~Color();

private:
    uint32_t _color;
};

#endif /* GLOBAL_TYPES_H */
