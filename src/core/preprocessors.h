#if !defined(CUSTOM_PREPROCESSORS_H)
#define CUSTOM_PREPROCESSORS_H

#include <memory>

#define DECLARE_SMART(class_name, spname) \
    class class_name;\
    typedef std::shared_ptr<class_name> spname;

#endif // CUSTOM_PREPROCESSORS_H
