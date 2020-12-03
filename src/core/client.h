#ifndef Client_H
#define Client_H


#include "../core/preprocessors.h"
#include <string>

using namespace std;


DECLARE_SMART(Client, spClient);

class Client {
public:
  Client();
  Client(const Client&);
  virtual ~Client();

  string username;
	string currentQuestName;

private:

};

#endif /* Client_H */
