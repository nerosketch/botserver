#include "BaseAPI.h"


IBaseAPI::IBaseAPI() {}
IBaseAPI::IBaseAPI(const IBaseAPI& o) {}
IBaseAPI::~IBaseAPI() {}

const std::string& IBaseAPI::get_content_type_header()
{
    return _default_content_type;
}

const std::string IBaseAPI::_default_content_type = "content-type: application/json";
