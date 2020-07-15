#include "user/GameUserManager.h"
#include "GameLogic.h"


std::string global_entrypoint_logic(GameInboxMessage& msg)
{
    // Найти игрока
    // Передать сообщение игроку

    GameUserManager& gum = GameUserManager::getInstance();
    spGameUser usr = gum.getUser("Username");
    if (usr) {
        usr->on_inbox_message(msg);
    }

    return "{"
           "\"It is a Telegram up\": true"
           "}";
}
