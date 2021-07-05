#if !defined(CUSTOM_PREPROCESSORS_H)
#define CUSTOM_PREPROCESSORS_H

#include <memory>

#define DECLARE_SMART(class_name, spname) \
    class class_name;\
    typedef std::shared_ptr<class_name> spname;


#ifndef DEBUG_STRUCT_LOG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STRUCT_LOG(text) std::cout << text << std::endl
#else
#define DEBUG_STRUCT_LOG(text)
#endif
#endif

#endif // CUSTOM_PREPROCESSORS_H
