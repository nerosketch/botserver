#ifndef ErrorBase_H
#define ErrorBase_H

#include <string>
#include "preprocessors.h"

using namespace std;

DECLARE_SMART(ErrorBase, spErrorBase);

class ErrorBase
{
public:
    ErrorBase();
    ErrorBase(const string &msg, int err_code);
    ErrorBase(const ErrorBase &);
    virtual ~ErrorBase();

    static spErrorBase makeError(const string &msg, int err_code = 0);

    const string& getMsg() const{
        return message_text;
    }

protected:
    string message_text;
    int error_num;
};

#endif /* ErrorBase_H */
