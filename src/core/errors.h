#ifndef ErrorBase_H
#define ErrorBase_H

#include "preprocessors.h"
#include <string>

using namespace std;

DECLARE_SMART(ErrorBase, spErrorBase);

class ErrorBase
{
public:
    ErrorBase();
    ErrorBase(const string &msg);
    ErrorBase(const string &msg, int err_code);
    ErrorBase(const ErrorBase &);
    virtual ~ErrorBase();

protected:
    string message_text;
    int error_num;
};

#endif /* ErrorBase_H */
