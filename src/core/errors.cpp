#include <iostream>
#include "errors.h"


namespace botserver {

  Error::Error() = default;

  Error::Error(const string &msg, int err_code)
      : message_text(msg), error_num(err_code) {}

  Error::Error(const Error &o) = default;

  Error::~Error() = default;

  spError Error::makeError(const string &msg, int err_code)
  {
      return make_shared<Error>(msg, err_code);
  }

  void Error::sendError(spError err)
  {
    sendError(err->message_text, err->error_num);
  }

  void Error::sendError(const string &msg, int err_code)
  {
    // Temporary. TODO: Make it functionality
    std::cerr << msg << " - " << err_code << std::endl;
  }

}
