#ifndef ClientStorage_H
#define ClientStorage_H

#include <unordered_map>
#include <string>
#include "client.h"

using namespace std;

class ClientStorage
{
public:
    static ClientStorage &getInstance()
    {
        static ClientStorage singletone;
        return singletone;
    }

    spClient FindClient(const string& name) const;
    bool DelClient(const string& name);
    void AddClient(spClient& client);

private:
    ClientStorage();
    ClientStorage(const ClientStorage &);
    virtual ~ClientStorage();
    ClientStorage &operator=(const ClientStorage &);

    unordered_map<string, spClient> clients;
};

#endif /* ClientStorage_H */
