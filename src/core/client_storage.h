#ifndef ClientStorage_H
#define ClientStorage_H

#include "client.h"
#include <map>
#include <string>

using namespace std;

class ClientStorage
{
public:
    static ClientStorage &getInstance()
    {
        static ClientStorage singletone;
        return singletone;
    }

    spClient FindClient(const string& name);
    bool DelClient(const string& name);
    void AddClient(spClient& client);

private:
    ClientStorage();
    ClientStorage(const ClientStorage &);
    virtual ~ClientStorage();
    ClientStorage &operator=(const ClientStorage &);

    map<string, spClient> clients;
};

#endif /* ClientStorage_H */
