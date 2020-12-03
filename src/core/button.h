#ifndef Button_H
#define Button_H


#include "../core/preprocessors.h"
#include <string>

DECLARE_SMART(Button, spButton);

using namespace std;

class Button {
public:
  Button();
  Button(const Button&);
  virtual ~Button();

  string Title;
	string NextDialogName;

private:

};

#endif /* Button_H */
