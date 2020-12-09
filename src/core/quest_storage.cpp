#include "quest_storage.h"

QuestStorage::QuestStorage() = default;

QuestStorage::QuestStorage(const QuestStorage &o) :
_quests_map(o._quests_map), _quests_map_m() {}

QuestStorage::~QuestStorage() = default;

QuestStorage &QuestStorage::getInstance()
{
    static QuestStorage singletone;
    return singletone;
}

spQuest QuestStorage::findQuest(const string &name) const
{
    const auto &quest_it = _quests_map.find(name);
    if (quest_it == _quests_map.end())
    {
        // quest not found
        return nullptr;
    }
    return quest_it->second;
}

bool QuestStorage::delQuest(const string &name)
{
    if (_quests_map.find(name) != _quests_map.end())
    {
        lock_guard<mutex> lg(_quests_map_m);

        const auto deleted_count = _quests_map.erase(name);
        return deleted_count != 0;
    }
    return false;
}

void QuestStorage::setQuests(const QuestMapType& quests)
{
    lock_guard<mutex> lg(_quests_map_m);

    _quests_map = quests;
}

spQuest QuestStorage::getDefaultQuest() const
{
    // FIXME: Currently first available quest.
    for (auto& pair : _quests_map)
    {
        return pair.second;
    }
    return nullptr;
}
