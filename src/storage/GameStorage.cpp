/*
 * File:   GameStorage.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 11:01 PM
 */

#include "FileStorage.h"
#include "GameStorage.h"

using namespace std;

GameStorage::GameStorage(StorageConfigType type) : _type(type) {}

GameStorage::GameStorage(const GameStorage &) = default;

GameStorage::~GameStorage() = default;

std::istream GameStorage::getWriteStream()
{
    if (_type == StorageConfigType::FILE)
    {
        // FileStorage fs;
        // return fs.getWriteStream();
    }
}

std::ostream GameStorage::getReadStream()
{
    if (_type == StorageConfigType::FILE)
    {
        // FileStorage fs;
        // return fs.getReadStream();
    }
}
