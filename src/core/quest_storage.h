#ifndef QuestStorage_H
#define QuestStorage_H

#include "preprocessors.h"
#include "quest.h"
#include <string>
#include <unordered_map>

using namespace std;

DECLARE_SMART(QuestStorage, spQuestStorage);

class QuestStorage
{
public:
    static QuestStorage &getInstance();

    spQuest findQuest(const string &name);
    bool delQuest(const string &name);
    void setQuests(unordered_map<string, spQuest> quests);
    spQuest getDefaultQuest();

private:
    QuestStorage();
    QuestStorage(const QuestStorage &);
    virtual ~QuestStorage();
    QuestStorage &operator=(const QuestStorage &);

    unordered_map<string, spQuest> _quests_map;
};

#endif /* QuestStorage_H */
