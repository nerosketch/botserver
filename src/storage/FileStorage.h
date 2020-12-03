/*
 * File:   FileStorage.h
 * Author: ns
 *
 * Created on June 29, 2020, 11:01 PM
 */

#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include "BaseStorage.h"

class FileStorage : public BaseStorage
{
public:
    FileStorage();

    FileStorage(const FileStorage &o);

    ~FileStorage() override;

    std::istream getWriteStream() override;
    std::ostream getReadStream() override;

private:
};

#endif /* FILESTORAGE_H */
