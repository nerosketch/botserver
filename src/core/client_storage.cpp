#include "client_storage.h"

ClientStorage::ClientStorage() = default;

ClientStorage::ClientStorage(const ClientStorage& o) :
clients(o.clients), _clients_m() {}

ClientStorage::~ClientStorage() = default;


spClient ClientStorage::FindClient(const string &name) const
{
    // clients.at(name);
    const auto &client_it = clients.find(name);
    if (client_it == clients.end())
    {
        // not found
        return nullptr;
    }
    return client_it->second;
}

bool ClientStorage::DelClient(const string &name)
{
    if (clients.find(name) != clients.end())
    {
        lock_guard<mutex> lg(_clients_m);

        const auto count_deleted = clients.erase(name);
        return count_deleted != 0;
    }
    return false;
}

void ClientStorage::AddClient(spClient &client)
{
    lock_guard<mutex> lg(_clients_m);

    clients[client->GetUsername()] = client;
}
