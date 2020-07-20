//
// Created by ns on 7/21/20.
//

#ifndef BOTSERVER_BASESTORAGE_H
#define BOTSERVER_BASESTORAGE_H

#include <iostream>

class BaseStorage {
public:
    BaseStorage() = default;
    BaseStorage(const BaseStorage&) = default;
    virtual ~BaseStorage() = default;

    virtual std::istream getWriteStream() = 0;
    virtual std::ostream getReadStream() = 0;
};


#endif //BOTSERVER_BASESTORAGE_H
