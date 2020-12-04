#include "client_storage.h"

ClientStorage::ClientStorage() = default;

ClientStorage::ClientStorage(const ClientStorage &o) = default;

ClientStorage::~ClientStorage() = default;


spClient ClientStorage::FindClient(const string &name)
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
    const auto count_deleted = clients.erase(name);
    return count_deleted != 0;
}

void ClientStorage::AddClient(spClient &client)
{
    clients.at(client->GetUsername()) = client;
}
