#ifndef QuestStorage_H
#define QuestStorage_H

#include <string>
#include <unordered_map>
#include "preprocessors.h"
#include "quest.h"

using namespace std;

DECLARE_SMART(QuestStorage, spQuestStorage);

typedef unordered_map<string, spQuest> QuestMapType;

class QuestStorage
{
public:
    static QuestStorage &getInstance();

    spQuest findQuest(const string &name);
    bool delQuest(const string &name);
    void setQuests(const QuestMapType& quests);
    spQuest getDefaultQuest();

private:
    QuestStorage();
    QuestStorage(const QuestStorage &);
    virtual ~QuestStorage();
    QuestStorage &operator=(const QuestStorage &);

    QuestMapType _quests_map;
};

#endif /* QuestStorage_H */
