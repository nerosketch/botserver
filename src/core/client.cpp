#include "client.h"

Client::Client() = default;

Client::Client(const string &uname)
:username(uname)
{}

Client::Client(const string &uname, const string &current_quest_name)
:username(uname), currentQuestName(current_quest_name)
{}

Client::Client(const Client &o) = default;

Client::~Client() = default;
