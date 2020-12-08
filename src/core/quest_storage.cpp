#include "quest_storage.h"

QuestStorage::QuestStorage() = default;

QuestStorage::QuestStorage(const QuestStorage &o) = default;

QuestStorage::~QuestStorage() = default;

QuestStorage &QuestStorage::getInstance()
{
    static QuestStorage singletone;
    return singletone;
}

spQuest QuestStorage::findQuest(const string &name)
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
    const auto deleted_count = _quests_map.erase(name);
    return deleted_count != 0;
}

void QuestStorage::setQuests(const QuestMapType& quests)
{
    _quests_map = quests;
}

spQuest QuestStorage::getDefaultQuest()
{
    // FIXME: Currently first available quest.
    for (auto& pair : _quests_map)
    {
        return pair.second;
    }
    return nullptr;
}
