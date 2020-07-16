/*
 * File:   TelegramAPI.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:59 PM
 */

#include <string.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../quest/GameInboxMessage.h"
#include "../GameLogic.h"
#include "TelegramAPI.h"


using nlohmann::json;
using namespace std;


TelegramAPI::TelegramAPI()
{
}

TelegramAPI::TelegramAPI(const TelegramAPI& o)
{
}

TelegramAPI::~TelegramAPI()
{
}


void TelegramAPI::on_get_message(const RequestParamsMap& params,
        const string& query_string, char* buffUot)
{
    // По идее get запросы telegram не шлёт через web hook.
}


void TelegramAPI::on_post_message(const RequestParamsMap& params,
        const string& post_data, const string& query_string, char* buffUot)
{
    // Сформировать объект сообщения
    // Передать сообщение в глобальную точку входа бота

    // uint32_t update_id, spTelegramMessage message, spTelegramInlineQuery inline_query,
    // spTelegramChosenInlineResult chosen_inline_result, spTelegramCallbackQuery callback_query
    uint32_t update_id = 0;
    string callback_query_id = "";
    string callback_query_inline_message_id = "";
    string callback_query_data = "";
    string chosen_inline_result_id = "";
    string chosen_inline_message_id = "";
    string chosen_inline_query = "";
    string inline_query_id = "";
    string inline_query_offset = "";
    string inline_query = "";
    int msg_id = 0;
    time_t msg_date = 0;
    time_t msg_forward_date = 0;
    string msg_text = "";
    string msg_caption = "";
    string msg_new_chat_title = "";
    vector<TelegramMessageEntity> msg_entities;
    spVectorTelegramPhotoSize msg_photo_sizes;
    spVectorTelegramPhotoSize msg_new_chat_photo_sizes;
    bool msg_delete_chat_photo = false;
    bool msg_group_chat_created = false;
    bool msg_supergroup_chat_created = false;
    bool msg_channel_chat_created = false;
    int msg_migrate_to_chat_id = 0;
    int msg_migrate_from_chat_id = 0;


    spTelegramUser msg_left_chat_member = make_shared<TelegramUser>(заполнить параметры);
    spTelegramUser msg_new_chat_member = make_shared<TelegramUser>(заполнить параметры);

    spTelegramVenue msg_venue = make_shared<TelegramVenue>(заполнить параметры);

    spTelegramContact msg_contact = make_shared<TelegramContact>(заполнить параметры);

    spTelegramVoice msg_voice = make_shared<TelegramVoice>(заполнить параметры);

    spTelegramVideo msg_video = make_shared<TelegramVideo>(заполнить параметры);

    spTelegramSticker msg_sticker = make_shared<TelegramSticker>(заполнить параметры);

    spTelegramDocument msg_document = make_shared<TelegramDocument>(заполнить параметры);

    spTelegramAudio msg_audio = make_shared<TelegramAudio>(заполнить параметры);

    spTelegramLocation location = make_shared<TelegramLocation>(заполнить параметры);

    spTelegramUser from = make_shared<TelegramUser>(заполнить параметры);

    spTelegramChat chat = make_shared<TelegramChat>(заполнить параметры);

    spTelegramUser forward_from = make_shared<TelegramUser>(заполнить параметры);

    spTelegramMessage msg = make_shared<TelegramMessage>(msg_id, from, msg_date,
            chat, forward_from, msg_forward_date, msg_text, msg_entities,
            msg_audio, msg_document, msg_photo_sizes, msg_sticker,
            msg_video, msg_voice, msg_caption, msg_contact, location,
            msg_venue, msg_new_chat_member, msg_left_chat_member,
            msg_new_chat_title, msg_new_chat_photo_sizes, msg_delete_chat_photo,
            msg_group_chat_created, msg_supergroup_chat_created,
            msg_channel_chat_created, msg_migrate_to_chat_id,
            msg_migrate_from_chat_id);

    spTelegramInlineQuery inline_query = make_shared<TelegramInlineQuery>(
            inline_query_id, from, location, inline_query,
            inline_query_offset);

    spTelegramChosenInlineResult chosen_inline_result = make_shared<TelegramChosenInlineResult>(
            chosen_inline_result_id, from, location, chosen_inline_message_id,
            chosen_inline_query);

    spTelegramCallbackQuery callback_query = make_shared<TelegramCallbackQuery>(
            callback_query_id, from, msg,
            callback_query_inline_message_id, callback_query_data);

    spTelegramWebhookUpdate update = make_shared<TelegramWebhookUpdate>(
            update_id, msg, inline_query,
            chosen_inline_result, callback_query);

    GameInboxMessage msg("User telegram game message");

    string result = global_entrypoint_logic(msg);
    strcpy(buffUot, result.c_str());
}


int TelegramAPI::setWebhook(const string& url)
{
    json j;
    j["pi"] = 3.141;
    cout << j << endl;
    return 0;
}


TelegramPhotoSize::TelegramPhotoSize()
{
}

TelegramPhotoSize::TelegramPhotoSize(const string& file_id, int width,
        int height, int file_size)
        :
        _file_id(file_id), _width(width), _height(height),
        _file_size(file_size)
{
}


TelegramPhotoSize::TelegramPhotoSize(const TelegramPhotoSize& o)
        :
        _file_id(o._file_id), _width(o._width), _height(o._height),
        _file_size(o._file_size)
{
}


TelegramPhotoSize::~TelegramPhotoSize()
{
}


string TelegramPhotoSize::GetFileId() const
{
    return _file_id;
}

void TelegramPhotoSize::SetFileId(const string& file_id)
{
    _file_id = file_id;
}

int TelegramPhotoSize::GetFileSize() const
{
    return _file_size;
}

void TelegramPhotoSize::SetFileSize(int file_size)
{
    _file_size = file_size;
}

int TelegramPhotoSize::GetHeight() const
{
    return _height;
}

void TelegramPhotoSize::SetHeight(int height)
{
    _height = height;
}

int TelegramPhotoSize::GetWidth() const
{
    return _width;
}

void TelegramPhotoSize::SetWidth(int width)
{
    _width = width;
}


TelegramVideo::TelegramVideo()
{
}

TelegramVideo::TelegramVideo(const string& file_id, int width, int height,
        int duration, spTelegramPhotoSize thumb, const string& mime_type,
        int file_size)
        :
        _file_id(file_id), _width(width), _height(height),
        _duration(duration), _thumb(thumb), _mime_type(mime_type),
        _file_size(file_size)
{
}


TelegramVideo::TelegramVideo(const TelegramVideo& o)
        :
        _file_id(o._file_id), _width(o._width), _height(o._height),
        _duration(o._duration), _thumb(o._thumb), _mime_type(o._mime_type),
        _file_size(o._file_size)
{
}

TelegramVideo::~TelegramVideo()
{
}


int TelegramVideo::GetDuration() const
{
    return _duration;
}

void TelegramVideo::SetDuration(int duration)
{
    _duration = duration;
}

string TelegramVideo::GetFileId() const
{
    return _file_id;
}

void TelegramVideo::SetFileId(const string& file_id)
{
    _file_id = file_id;
}

int TelegramVideo::GetFileSize() const
{
    return _file_size;
}

void TelegramVideo::SetFileSize(int file_size)
{
    _file_size = file_size;
}

int TelegramVideo::GetHeight() const
{
    return _height;
}

void TelegramVideo::SetHeight(int height)
{
    _height = height;
}

const string& TelegramVideo::GetMimeType() const
{
    return _mime_type;
}

void TelegramVideo::SetMimeType(const string& mime_type)
{
    _mime_type = mime_type;
}

spTelegramPhotoSize TelegramVideo::GetThumb() const
{
    return _thumb;
}

void TelegramVideo::SetThumb(spTelegramPhotoSize thumb)
{
    _thumb = thumb;
}

int TelegramVideo::GetWidth() const
{
    return _width;
}

void TelegramVideo::SetWidth(int width)
{
    _width = width;
}


TelegramVoice::TelegramVoice()
{
}

TelegramVoice::TelegramVoice(const TelegramVoice& o)
{
}

TelegramVoice::~TelegramVoice()
{
}

int
TelegramVoice::GetDuration() const
{
    return _duration;
}

void
TelegramVoice::SetDuration(int duration)
{
    _duration = duration;
}

string
TelegramVoice::GetFileId() const
{
    return _file_id;
}

void
TelegramVoice::SetFileId(const string& file_id)
{
    _file_id = file_id;
}

int
TelegramVoice::GetFileSize() const
{
    return _file_size;
}

void
TelegramVoice::SetFileSize(int file_size)
{
    _file_size = file_size;
}

string
TelegramVoice::GetMimeType() const
{
    return _mime_type;
}

void
TelegramVoice::SetMimeType(const string& mime_type)
{
    _mime_type = mime_type;
}



TelegramContact::TelegramContact()
{
}

TelegramContact::TelegramContact(const TelegramContact& o)
{
}

TelegramContact::~TelegramContact()
{
}


const string&
TelegramContact::GetFirstName() const
{
    return _first_name;
}

void
TelegramContact::SetFirstName(const string& first_name)
{
    _first_name = first_name;
}

const string&
TelegramContact::GetLastName() const
{
    return _last_name;
}

void
TelegramContact::SetLastName(const string& last_name)
{
    _last_name = last_name;
}

const string&
TelegramContact::GetPhoneNumber() const
{
    return _phone_number;
}

void
TelegramContact::SetPhoneNumber(const string& phone_number)
{
    _phone_number = phone_number;
}

int
TelegramContact::GetUserId() const
{
    return _user_id;
}

void
TelegramContact::SetUserId(int user_id)
{
    _user_id = user_id;
}



TelegramLocation::TelegramLocation() = default;

TelegramLocation::TelegramLocation(const TelegramLocation& o) = default;

TelegramLocation::~TelegramLocation() = default;


TelegramVenue::TelegramVenue()
{
}

TelegramVenue::TelegramVenue(const TelegramVenue& o)
{
}

TelegramVenue::~TelegramVenue()
{
}


TelegramUserProfilePhotos::TelegramUserProfilePhotos()
{
}

TelegramUserProfilePhotos::TelegramUserProfilePhotos(const TelegramUserProfilePhotos& o)
{
}

TelegramUserProfilePhotos::~TelegramUserProfilePhotos()
{
}


TelegramSticker::TelegramSticker()
{
}

TelegramSticker::TelegramSticker(const TelegramSticker& o)
{
}

TelegramSticker::~TelegramSticker()
{
}


TelegramAudio::TelegramAudio()
{
}

TelegramAudio::TelegramAudio(const TelegramAudio& o)
{
}

TelegramAudio::~TelegramAudio()
{
}


TelegramDocument::TelegramDocument()
{
}

TelegramDocument::TelegramDocument(const TelegramDocument& o)
{
}

TelegramDocument::~TelegramDocument()
{
}


TelegramChat::TelegramChat()
{
}

TelegramChat::TelegramChat(const TelegramChat& o)
{
}

TelegramChat::~TelegramChat()
{
}


TelegramUser::TelegramUser()
{
}

TelegramUser::TelegramUser(const TelegramUser& o)
{
}

TelegramUser::~TelegramUser()
{
}


TelegramCallbackQuery::TelegramCallbackQuery()
{
}

TelegramCallbackQuery::TelegramCallbackQuery(const TelegramCallbackQuery& o)
{
}

TelegramCallbackQuery::~TelegramCallbackQuery()
{
}


TelegramChosenInlineResult::TelegramChosenInlineResult()
{
}


TelegramChosenInlineResult::TelegramChosenInlineResult(const string& result_id,
        spTelegramUser from,
        spTelegramLocation location,
        string inline_message_id, string query)
        :
        _result_id(result_id),
        _from(from),
        _location(location),
        _inline_message_id(inline_message_id),
        _query(query)
{
}


TelegramChosenInlineResult::TelegramChosenInlineResult(const TelegramChosenInlineResult& o)
        :
        _result_id(o._result_id),
        _from(o._from),
        _location(o._location),
        _inline_message_id(o._inline_message_id),
        _query(o._query)
{
}


TelegramChosenInlineResult::~TelegramChosenInlineResult()
{
}


spTelegramUser TelegramChosenInlineResult::GetFrom() const
{
    return _from;
}

void TelegramChosenInlineResult::SetFrom(spTelegramUser from)
{
    _from = from;
}

string TelegramChosenInlineResult::GetInlineMessageId() const
{
    return _inline_message_id;
}

void TelegramChosenInlineResult::SetInlineMessageId(const string& inline_message_id)
{
    _inline_message_id = inline_message_id;
}

spTelegramLocation TelegramChosenInlineResult::GetLocation() const
{
    return _location;
}

void TelegramChosenInlineResult::SetLocation(spTelegramLocation location)
{
    _location = location;
}

string TelegramChosenInlineResult::GetQuery() const
{
    return _query;
}

void TelegramChosenInlineResult::SetQuery(const string& query)
{
    _query = query;
}

string TelegramChosenInlineResult::GetResultId() const
{
    return _result_id;
}

void TelegramChosenInlineResult::SetResultId(const string& result_id)
{
    _result_id = result_id;
}


TelegramInlineQuery::TelegramInlineQuery()
{
}


TelegramInlineQuery::TelegramInlineQuery(const string& id, spTelegramUser from,
        spTelegramLocation location, const string& query, const string& offset)
        :
        _id(id), _from(from), _location(location), _query(query), _offset(offset)
{
}


TelegramInlineQuery::TelegramInlineQuery(const TelegramInlineQuery& o) = default;


TelegramInlineQuery::~TelegramInlineQuery()
{
}


spTelegramUser TelegramInlineQuery::GetFrom() const
{
    return _from;
}

void TelegramInlineQuery::SetFrom(spTelegramUser from)
{
    _from = from;
}

string TelegramInlineQuery::GetId() const
{
    return _id;
}

void TelegramInlineQuery::SetId(const string& id)
{
    _id = id;
}

spTelegramLocation TelegramInlineQuery::GetLocation() const
{
    return _location;
}

void TelegramInlineQuery::SetLocation(spTelegramLocation location)
{
    _location = location;
}

string TelegramInlineQuery::GetOffset() const
{
    return _offset;
}

void TelegramInlineQuery::SetOffset(const string& offset)
{
    _offset = offset;
}

string TelegramInlineQuery::GetQuery() const
{
    return _query;
}

void TelegramInlineQuery::SetQuery(const string& query)
{
    _query = query;
}


TelegramMessageEntity::TelegramMessageEntity()
{
}

TelegramMessageEntity::TelegramMessageEntity(const TelegramMessageEntity& o) = default;

TelegramMessageEntity::~TelegramMessageEntity()
{
}


TelegramMessage::TelegramMessage()
{
}

TelegramMessage::TelegramMessage(int message_id, spTelegramUser from, time_t date, spTelegramChat chat,
        spTelegramUser forward_from, time_t forward_date, const string& text,
        const vector<TelegramMessageEntity>& entities, spTelegramAudio audio,
        spTelegramDocument document, spVectorTelegramPhotoSize photo,
        spTelegramSticker sticker, spTelegramVideo video,
        spTelegramVoice voice, const string& caption, spTelegramContact contact,
        spTelegramLocation location, spTelegramVenue venue,
        spTelegramUser new_chat_member, spTelegramUser left_chat_member,
        const string& new_chat_title, spVectorTelegramPhotoSize new_chat_photo,
        bool delete_chat_photo, bool group_chat_created,
        bool supergroup_chat_created, bool channel_chat_created,
        int migrate_to_chat_id, int migrate_from_chat_id)
        :
        _message_id(message_id), _from(from), _date(date), _chat(chat), _forward_from(forward_from),
        _forward_date(forward_date), _text(text), _entities(entities),
        _audio(audio), _document(document), _photo(photo), _sticker(sticker),
        _video(video), _voice(voice), _caption(caption), _contact(contact),
        _location(location), _venue(venue), _new_chat_member(new_chat_member),
        _left_chat_member(left_chat_member), _new_chat_title(new_chat_title),
        _new_chat_photo(new_chat_photo), _delete_chat_photo(delete_chat_photo),
        _group_chat_created(group_chat_created),
        _supergroup_chat_created(supergroup_chat_created),
        _channel_chat_created(channel_chat_created), _migrate_to_chat_id(migrate_to_chat_id),
        _migrate_from_chat_id(migrate_from_chat_id)
{
}

TelegramMessage::TelegramMessage(const TelegramMessage& o) = default;


TelegramMessage::~TelegramMessage()
{
}


spTelegramAudio TelegramMessage::GetAudio() const
{
    return _audio;
}

void TelegramMessage::SetAudio(spTelegramAudio audio)
{
    _audio = audio;
}

string TelegramMessage::GetCaption() const
{
    return _caption;
}

void TelegramMessage::SetCaption(const string& caption)
{
    _caption = caption;
}

bool TelegramMessage::IsChannelChatCreated() const
{
    return _channel_chat_created;
}

void TelegramMessage::SetChannelChatCreated(bool channel_chat_created)
{
    _channel_chat_created = channel_chat_created;
}

spTelegramChat TelegramMessage::GetChat() const
{
    return _chat;
}

void TelegramMessage::SetChat(spTelegramChat chat)
{
    _chat = chat;
}

spTelegramContact TelegramMessage::GetContact() const
{
    return _contact;
}

void TelegramMessage::SetContact(spTelegramContact contact)
{
    _contact = contact;
}

time_t TelegramMessage::GetDate() const
{
    return _date;
}

void TelegramMessage::SetDate(time_t date)
{
    _date = date;
}

bool TelegramMessage::IsDeleteChatPhoto() const
{
    return _delete_chat_photo;
}

void TelegramMessage::SetDeleteChatPhoto(bool delete_chat_photo)
{
    _delete_chat_photo = delete_chat_photo;
}

spTelegramDocument TelegramMessage::GetDocument() const
{
    return _document;
}

void TelegramMessage::SetDocument(spTelegramDocument document)
{
    _document = document;
}

vector<TelegramMessageEntity> TelegramMessage::GetEntities() const
{
    return _entities;
}

void TelegramMessage::SetEntities(vector<TelegramMessageEntity> entities)
{
    _entities = entities;
}

time_t TelegramMessage::GetForwardDate() const
{
    return _forward_date;
}

void TelegramMessage::SetForwardDate(time_t forward_date)
{
    _forward_date = forward_date;
}

spTelegramUser TelegramMessage::GetForwardFrom() const
{
    return _forward_from;
}

void TelegramMessage::SetForwardFrom(spTelegramUser forward_from)
{
    _forward_from = forward_from;
}

spTelegramUser TelegramMessage::GetFrom() const
{
    return _from;
}

void TelegramMessage::SetFrom(spTelegramUser from)
{
    _from = from;
}

bool TelegramMessage::IsGroupChatCreated() const
{
    return _group_chat_created;
}

void TelegramMessage::SetGroupChatCreated(bool group_chat_created)
{
    _group_chat_created = group_chat_created;
}

spTelegramUser TelegramMessage::GetLeftChatMember() const
{
    return _left_chat_member;
}

void TelegramMessage::SetLeftChatMember(spTelegramUser left_chat_member)
{
    _left_chat_member = left_chat_member;
}

spTelegramLocation TelegramMessage::GetLocation() const
{
    return _location;
}

void TelegramMessage::SetLocation(spTelegramLocation location)
{
    _location = location;
}

int TelegramMessage::GetMessageId() const
{
    return _message_id;
}

void TelegramMessage::SetMessageId(int message_id)
{
    _message_id = message_id;
}

int TelegramMessage::GetMigrateFromChatId() const
{
    return _migrate_from_chat_id;
}

void TelegramMessage::SetMigrateFromChatId(int migrate_from_chat_id)
{
    _migrate_from_chat_id = migrate_from_chat_id;
}

int TelegramMessage::GetMigrateToChatId() const
{
    return _migrate_to_chat_id;
}

void TelegramMessage::SetMigrateToChatId(int migrate_to_chat_id)
{
    _migrate_to_chat_id = migrate_to_chat_id;
}

spTelegramUser TelegramMessage::GetNewChatMember() const
{
    return _new_chat_member;
}

void TelegramMessage::SetNewChatMember(spTelegramUser new_chat_member)
{
    _new_chat_member = new_chat_member;
}

spVectorTelegramPhotoSize TelegramMessage::GetNewChatPhoto() const
{
    return _new_chat_photo;
}

void TelegramMessage::SetNewChatPhoto(spVectorTelegramPhotoSize new_chat_photo)
{
    _new_chat_photo = new_chat_photo;
}

string TelegramMessage::GetNewChatTitle() const
{
    return _new_chat_title;
}

void TelegramMessage::SetNewChatTitle(const string& new_chat_title)
{
    _new_chat_title = new_chat_title;
}

spVectorTelegramPhotoSize TelegramMessage::GetPhoto() const
{
    return _photo;
}

void TelegramMessage::SetPhoto(spVectorTelegramPhotoSize photo)
{
    _photo = photo;
}

spTelegramSticker TelegramMessage::GetSticker() const
{
    return _sticker;
}

void TelegramMessage::SetSticker(spTelegramSticker sticker)
{
    _sticker = sticker;
}

bool TelegramMessage::IsSupergroupChatCreated() const
{
    return _supergroup_chat_created;
}

void TelegramMessage::SetSupergroupChatCreated(bool supergroup_chat_created)
{
    _supergroup_chat_created = supergroup_chat_created;
}

string TelegramMessage::GetText() const
{
    return _text;
}

void TelegramMessage::SetText(const string& text)
{
    _text = text;
}

spTelegramVenue TelegramMessage::GetVenue() const
{
    return _venue;
}

void TelegramMessage::SetVenue(spTelegramVenue venue)
{
    _venue = venue;
}

spTelegramVideo TelegramMessage::GetVideo() const
{
    return _video;
}

void TelegramMessage::SetVideo(spTelegramVideo video)
{
    _video = video;
}

spTelegramVoice TelegramMessage::GetVoice() const
{
    return _voice;
}

void TelegramMessage::SetVoice(spTelegramVoice voice)
{
    _voice = voice;
}


TelegramWebhookUpdate::TelegramWebhookUpdate()
{
}

TelegramWebhookUpdate::TelegramWebhookUpdate(const TelegramWebhookUpdate& o)
{
}

TelegramWebhookUpdate::~TelegramWebhookUpdate()
{
}

TelegramWebhookUpdate::TelegramWebhookUpdate(uint32_t update_id,
        spTelegramMessage message,
        spTelegramInlineQuery inline_query,
        spTelegramChosenInlineResult chosen_inline_result,
        spTelegramCallbackQuery callback_query)
        :
        _update_id(update_id), _message(message), _inline_query(inline_query),
        _chosen_inline_result(chosen_inline_result), _callback_query(callback_query)
{
}

spTelegramMessage TelegramWebhookUpdate::GetMessage() const
{
    return _message;
}

void TelegramWebhookUpdate::SetMessage(spTelegramMessage message)
{
    _message = message;
}

uint32_t TelegramWebhookUpdate::GetUpdateId() const
{
    return _update_id;
}

void TelegramWebhookUpdate::SetUpdateId(uint32_t update_id)
{
    _update_id = update_id;
}

spTelegramCallbackQuery TelegramWebhookUpdate::GetCallbackQuery() const
{
    return _callback_query;
}

void TelegramWebhookUpdate::SetCallbackQuery(spTelegramCallbackQuery callback_query)
{
    _callback_query = callback_query;
}

spTelegramChosenInlineResult TelegramWebhookUpdate::GetChosenInlineResult() const
{
    return _chosen_inline_result;
}

void TelegramWebhookUpdate::SetChosenInlineResult(spTelegramChosenInlineResult chosen_inline_result)
{
    _chosen_inline_result = chosen_inline_result;
}

spTelegramInlineQuery TelegramWebhookUpdate::GetInlineQuery() const
{
    return _inline_query;
}

void TelegramWebhookUpdate::SetInlineQuery(spTelegramInlineQuery inline_query)
{
    _inline_query = inline_query;
}
