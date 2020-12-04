#include "errors.h"

ErrorBase::ErrorBase() = default;

ErrorBase::ErrorBase(const string &msg, int err_code)
    : message_text(msg), error_num(err_code) {}

ErrorBase::ErrorBase(const ErrorBase &o) = default;

ErrorBase::~ErrorBase() = default;

spErrorBase ErrorBase::makeError(const string &msg, int err_code)
{
    return make_shared<ErrorBase>(msg, err_code);
}
