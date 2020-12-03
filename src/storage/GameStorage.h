/*
 * File:   GameStorage.h
 * Author: ns
 *
 * Created on June 29, 2020, 11:01 PM
 */

#ifndef GAMESTORAGE_H
#define GAMESTORAGE_H

#include "BaseStorage.h"

enum class StorageConfigType
{
    FILE
};

class GameStorage : public BaseStorage
{
public:
    explicit GameStorage(StorageConfigType type);

    GameStorage(const GameStorage &o);

    ~GameStorage() override;

    std::istream getWriteStream() override;
    std::ostream getReadStream() override;

private:
    StorageConfigType _type;
};

#endif /* GAMESTORAGE_H */
