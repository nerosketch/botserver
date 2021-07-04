#ifndef Error_H
#define Error_H

#include <string>
#include "preprocessors.h"

using namespace std;

namespace botserver {

  DECLARE_SMART(Error, spError);

  class Error
  {
  public:
      Error();
      Error(const string &msg, int err_code);
      Error(const Error &);
      virtual ~Error();

      static spError makeError(const string &msg, int err_code = 0);

      const string& getMsg() const{
          return message_text;
      }

  protected:
      string message_text;
      int error_num;
  };

}
#endif /* Error_H */
