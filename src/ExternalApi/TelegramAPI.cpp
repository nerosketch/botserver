/*
 * File:   TelegramAPI.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:59 PM
 */

#include <string.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include "TelegramAPI.h"


using nlohmann::json;
using namespace std;


TelegramAPI::TelegramAPI () { }

TelegramAPI::TelegramAPI (const TelegramAPI& o) { }

TelegramAPI::~TelegramAPI () { }

void TelegramAPI::on_get_message(const RequestParamsMap& params, const string& query_string, char *buffUot)
{
    strcpy(buffUot, "{"
        "\"It is a Telegram up\": true"
        "}"
    );

    // Сформировать объект сообщения
    // Найти игрока
    // Передать сообщение игроку
}
void TelegramAPI::on_post_message(const RequestParamsMap& params, const string& post_data, const string& query_string, char *buffUot)
{
  
}

int TelegramAPI::setWebhook(const string& url)
{
  json j;
  j["pi"] = 3.141;
  cout << j << endl;
  return 0;
}


TelegramPhotoSize::TelegramPhotoSize () { }

TelegramPhotoSize::TelegramPhotoSize (const TelegramPhotoSize& o) { }

TelegramPhotoSize::~TelegramPhotoSize () { }




TelegramVideo::TelegramVideo () { }

TelegramVideo::TelegramVideo (const TelegramVideo& o) { }

TelegramVideo::~TelegramVideo () { }




TelegramVoice::TelegramVoice () { }

TelegramVoice::TelegramVoice (const TelegramVoice& o) { }

TelegramVoice::~TelegramVoice () { }




TelegramContact::TelegramContact () { }

TelegramContact::TelegramContact (const TelegramContact& o) { }

TelegramContact::~TelegramContact () { }




TelegramLocation::TelegramLocation () { }

TelegramLocation::TelegramLocation (const TelegramLocation& o) { }

TelegramLocation::~TelegramLocation () { }




TelegramVenue::TelegramVenue () { }

TelegramVenue::TelegramVenue (const TelegramVenue& o) { }

TelegramVenue::~TelegramVenue () { }




TelegramUserProfilePhotos::TelegramUserProfilePhotos () { }

TelegramUserProfilePhotos::TelegramUserProfilePhotos (const TelegramUserProfilePhotos& o) { }

TelegramUserProfilePhotos::~TelegramUserProfilePhotos () { }




TelegramSticker::TelegramSticker () { }

TelegramSticker::TelegramSticker (const TelegramSticker& o) { }

TelegramSticker::~TelegramSticker () { }




TelegramAudio::TelegramAudio () { }

TelegramAudio::TelegramAudio (const TelegramAudio& o) { }

TelegramAudio::~TelegramAudio () { }




TelegramDocument::TelegramDocument () { }

TelegramDocument::TelegramDocument (const TelegramDocument& o) { }

TelegramDocument::~TelegramDocument () { }




TelegramChat::TelegramChat () { }

TelegramChat::TelegramChat (const TelegramChat& o) { }

TelegramChat::~TelegramChat () { }




TelegramUser::TelegramUser () { }

TelegramUser::TelegramUser (const TelegramUser& o) { }

TelegramUser::~TelegramUser () { }




TelegramCallbackQuery::TelegramCallbackQuery () { }

TelegramCallbackQuery::TelegramCallbackQuery (const TelegramCallbackQuery& o) { }

TelegramCallbackQuery::~TelegramCallbackQuery () { }




TelegramChosenInlineResult::TelegramChosenInlineResult () { }

TelegramChosenInlineResult::TelegramChosenInlineResult (const TelegramChosenInlineResult& o) { }

TelegramChosenInlineResult::~TelegramChosenInlineResult () { }




TelegramInlineQuery::TelegramInlineQuery () { }

TelegramInlineQuery::TelegramInlineQuery (const TelegramInlineQuery& o) { }

TelegramInlineQuery::~TelegramInlineQuery () { }




TelegramMessageEntity::TelegramMessageEntity () { }

TelegramMessageEntity::TelegramMessageEntity (const TelegramMessageEntity& o) { }

TelegramMessageEntity::~TelegramMessageEntity () { }




TelegramMessage::TelegramMessage () { }

TelegramMessage::TelegramMessage (const TelegramMessage& o) { }

TelegramMessage::~TelegramMessage () { }




TelegramWebhookUpdate::TelegramWebhookUpdate () { }

TelegramWebhookUpdate::TelegramWebhookUpdate (const TelegramWebhookUpdate& o) { }

TelegramWebhookUpdate::~TelegramWebhookUpdate () { }
