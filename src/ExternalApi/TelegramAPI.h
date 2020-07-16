/*
 * File:   TelegramAPI.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:59 PM
 */

#ifndef TELEGRAMAPI_H
#define TELEGRAMAPI_H

#include <string>
#include <memory>
#include <ctime>
#include <vector>
#include "BaseAPI.h"

using namespace std;

/*
TelegramPhotoSize
TelegramVideo
TelegramVoice
TelegramContact
TelegramLocation
TelegramVenue
TelegramUserProfilePhotos
TelegramSticker
TelegramAudio
TelegramDocument
TelegramChat
TelegramUser
TelegramCallbackQuery
TelegramChosenInlineResult
TelegramInlineQuery
TelegramMessageEntity
TelegramMessage
TelegramWebhookUpdate
*/

class TelegramPhotoSize;

typedef shared_ptr<TelegramPhotoSize> spTelegramPhotoSize;
typedef vector<spTelegramPhotoSize> spVectorTelegramPhotoSize;

class TelegramVideo;

typedef shared_ptr<TelegramVideo> spTelegramVideo;

class TelegramVoice;

typedef shared_ptr<TelegramVoice> spTelegramVoice;

class TelegramContact;

typedef shared_ptr<TelegramContact> spTelegramContact;

class TelegramLocation;

typedef shared_ptr<TelegramLocation> spTelegramLocation;

class TelegramVenue;

typedef shared_ptr<TelegramVenue> spTelegramVenue;

class TelegramUserProfilePhotos;

typedef shared_ptr<TelegramUserProfilePhotos> spTelegramUserProfilePhotos;

class TelegramSticker;

typedef shared_ptr<TelegramSticker> spTelegramSticker;

class TelegramAudio;

typedef shared_ptr<TelegramAudio> spTelegramAudio;

class TelegramDocument;

typedef shared_ptr<TelegramDocument> spTelegramDocument;

class TelegramChat;

typedef shared_ptr<TelegramChat> spTelegramChat;

class TelegramUser;

typedef shared_ptr<TelegramUser> spTelegramUser;

class TelegramCallbackQuery;

typedef shared_ptr<TelegramCallbackQuery> spTelegramCallbackQuery;

class TelegramChosenInlineResult;

typedef shared_ptr<TelegramChosenInlineResult> spTelegramChosenInlineResult;

class TelegramInlineQuery;

typedef shared_ptr<TelegramInlineQuery> spTelegramInlineQuery;

class TelegramMessageEntity;

class TelegramMessage;

typedef shared_ptr<TelegramMessage> spTelegramMessage;

class TelegramWebhookUpdate;

typedef shared_ptr<TelegramWebhookUpdate> spTelegramWebhookUpdate;


class TelegramPhotoSize {
public:
    TelegramPhotoSize();

    TelegramPhotoSize(const string& file_id, int width, int height, int file_size);

    TelegramPhotoSize(const TelegramPhotoSize&);

    virtual ~TelegramPhotoSize();

    string GetFileId() const;

    void SetFileId(const string& file_id);

    int GetFileSize() const;

    void SetFileSize(int file_size);

    int GetHeight() const;

    void SetHeight(int height);

    int GetWidth() const;

    void SetWidth(int _width);

private:
    string _file_id;
    int _width;
    int _height;
    int _file_size;
};


class TelegramVideo {
public:
    TelegramVideo();

    TelegramVideo(const string& file_id, int width, int height, int duration,
            spTelegramPhotoSize thumb, const string& mime_type,
            int file_size);

    TelegramVideo(const TelegramVideo&);

    virtual ~TelegramVideo();

    int GetDuration() const;

    void SetDuration(int duration);

    string GetFileId() const;

    void SetFileId(const string& file_id);

    int GetFileSize() const;

    void SetFileSize(int _file_size);

    int GetHeight() const;

    void SetHeight(int height);

    string GetMimeType() const;

    void SetMimeType(const string& mime_type);

    spTelegramPhotoSize GetThumb() const;

    void SetThumb(spTelegramPhotoSize thumb);

    int GetWidth() const;

    void SetWidth(int width);

private:
    string _file_id;
    int _width;
    int _height;
    int _duration;
    spTelegramPhotoSize _thumb;
    string _mime_type;
    int _file_size;
};


class TelegramVoice {
public:
    TelegramVoice();

    TelegramVoice(const string& file_id, int duration, const string& mime_type, int file_size)
            :
            _file_id(file_id), _duration(duration), _mime_type(mime_type), _file_size(file_size)
    {
    }

    TelegramVoice(const TelegramVoice&);

    virtual ~TelegramVoice();

    int
    GetDuration() const;

    void
    SetDuration(int duration);

    string
    GetFileId() const;

    void
    SetFileId(const string& file_id);

    int
    GetFileSize() const;

    void
    SetFileSize(int file_size);

    const string&
    GetMimeType() const;

    void
    SetMimeType(const string& mime_type);

private:
    string _file_id;
    int _duration;
    string _mime_type;
    int _file_size;
};


class TelegramContact {
public:
    TelegramContact();

    TelegramContact(const string& phone_number, const string& first_name, const string& last_name, int user_id)
            :
            _phone_number(phone_number), _first_name(first_name), _last_name(last_name), _user_id(user_id)
    {
    }

    TelegramContact(const TelegramContact&);

    virtual ~TelegramContact();

    const string&
    GetFirstName() const;

    void
    SetFirstName(const string& first_name);

    const string&
    GetLastName() const;

    void
    SetLastName(const string& last_name);

    const string&
    GetPhoneNumber() const;

    void
    SetPhoneNumber(const string& phone_number);

    int
    GetUserId() const;

    void
    SetUserId(int user_id);

private:
    string _phone_number;
    string _first_name;
    string _last_name;
    int _user_id;
};


class TelegramLocation {
public:
    TelegramLocation();

    TelegramLocation(float _longitude, float latitude)
            :
            _longitude(_longitude), _latitude(latitude)
    {
    }

    TelegramLocation(const TelegramLocation&);

    virtual ~TelegramLocation();

    float
    GetLongitude() const
    {
        return _longitude;
    }

    void
    SetLongitude(float longitude)
    {
        _longitude = longitude;
    }

    float
    GetLatitude() const
    {
        return _latitude;
    }

    void
    SetLatitude(float latitude)
    {
        _latitude = latitude;
    }

private:
    float _longitude;
    float _latitude;
};


class TelegramVenue {
public:
    TelegramVenue();

    TelegramVenue(const spTelegramLocation& location, const string& title, const string& address, const string& foursquare_id)
            :
            _location(location), _title(title), _address(address), _foursquare_id(foursquare_id)
    {
    }

    TelegramVenue(const TelegramVenue&);

    virtual ~TelegramVenue();

    string
    GetAddress() const
    {
        return _address;
    }

    void
    SetAddress(const string& address)
    {
        _address = address;
    }

    string
    GetFoursquare_id() const
    {
        return _foursquare_id;
    }

    void
    SetFoursquare_id(const string& foursquare_id)
    {
        _foursquare_id = foursquare_id;
    }

    spTelegramLocation
    GetLocation() const
    {
        return _location;
    }

    void
    SetLocation(const spTelegramLocation& location)
    {
        _location = location;
    }

    string
    GetTitle() const
    {
        return _title;
    }

    void
    SetTitle(const string& title)
    {
        _title = title;
    }

private:
    spTelegramLocation _location;
    string _title;
    string _address;
    string _foursquare_id;
};


class TelegramUserProfilePhotos {
public:
    TelegramUserProfilePhotos();

    TelegramUserProfilePhotos(int total_count, const spVectorTelegramPhotoSize& photos)
            :
            _total_count(total_count), _photos(photos)
    {
    }

    TelegramUserProfilePhotos(const TelegramUserProfilePhotos&);

    virtual ~TelegramUserProfilePhotos();

    spVectorTelegramPhotoSize
    GetPhotos() const
    {
        return _photos;
    }

    void
    SetPhotos(spVectorTelegramPhotoSize photos)
    {
        _photos = photos;
    }

    int
    GetTotal_count() const
    {
        return _total_count;
    }

    void
    SetTotal_count(int total_count)
    {
        _total_count = total_count;
    }

private:
    int _total_count;
    spVectorTelegramPhotoSize _photos;
};


class TelegramSticker {
public:
    TelegramSticker();

    TelegramSticker(const string& file_id, int width, int height, const spTelegramPhotoSize& thumb, int file_size)
            :
            _file_id(file_id), _width(width), _height(height), _thumb(thumb), _file_size(file_size)
    {
    }

    TelegramSticker(const TelegramSticker&);

    virtual ~TelegramSticker();

    string
    GetFile_id() const
    {
        return _file_id;
    }

    void
    SetFile_id(const string& file_id)
    {
        _file_id = file_id;
    }

    int
    GetFileSize() const
    {
        return _file_size;
    }

    void
    SetFile_size(int file_size)
    {
        _file_size = file_size;
    }

    int
    GetHeight() const
    {
        return _height;
    }

    void
    SetHeight(int height)
    {
        _height = height;
    }

    spTelegramPhotoSize
    GetThumb() const
    {
        return _thumb;
    }

    void
    SetThumb(spTelegramPhotoSize thumb)
    {
        _thumb = thumb;
    }

    int
    GetWidth() const
    {
        return _width;
    }

    void
    SetWidth(int width)
    {
        _width = width;
    }

private:
    string _file_id;
    int _width;
    int _height;
    spTelegramPhotoSize _thumb;
    int _file_size;
};


class TelegramAudio {
public:
    TelegramAudio();

    TelegramAudio(const string& file_id, int duration, const string& performer, const string& title,
            const string& mime_type, int file_size)
            :
            _file_id(file_id), _duration(duration), _performer(performer), _title(title), _mime_type(mime_type),
            _file_size(file_size)
    {
    }

    TelegramAudio(const TelegramAudio&);

    virtual ~TelegramAudio();

    int
    GetDuration() const
    {
        return _duration;
    }

    void
    SetDuration(int duration)
    {
        _duration = duration;
    }

    string
    GetFile_id() const
    {
        return _file_id;
    }

    void
    SetFile_id(const string& file_id)
    {
        _file_id = file_id;
    }

    int
    GetFile_size() const
    {
        return _file_size;
    }

    void
    SetFile_size(int file_size)
    {
        _file_size = file_size;
    }

    string
    GetMime_type() const
    {
        return _mime_type;
    }

    void
    SetMime_type(const string& mime_type)
    {
        _mime_type = mime_type;
    }

    string
    GetPerformer() const
    {
        return _performer;
    }

    void
    SetPerformer(const string& performer)
    {
        _performer = performer;
    }

    string
    GetTitle() const
    {
        return _title;
    }

    void
    SetTitle(const string& title)
    {
        _title = title;
    }

private:
    string _file_id;
    int _duration;
    string _performer;
    string _title;
    string _mime_type;
    int _file_size;
};


class TelegramDocument {
public:
    TelegramDocument();

    TelegramDocument(const string& file_id, const spTelegramPhotoSize& thumb, const string& file_name, const string& mime_type,
            int file_size)
            :
            _file_id(file_id), _thumb(thumb), _file_name(file_name), _mime_type(mime_type), _file_size(file_size)
    {
    }

    TelegramDocument(const TelegramDocument&);

    virtual ~TelegramDocument();

    string
    GetFile_id() const
    {
        return _file_id;
    }

    void
    SetFile_id(const string& file_id)
    {
        _file_id = file_id;
    }

    string
    GetFile_name() const
    {
        return _file_name;
    }

    void
    SetFile_name(const string& file_name)
    {
        _file_name = file_name;
    }

    int
    GetFile_size() const
    {
        return _file_size;
    }

    void
    SetFile_size(int file_size)
    {
        _file_size = file_size;
    }

    string
    GetMime_type() const
    {
        return _mime_type;
    }

    void
    SetMime_type(const string& mime_type)
    {
        _mime_type = mime_type;
    }

    spTelegramPhotoSize
    GetThumb() const
    {
        return _thumb;
    }

    void
    SetThumb(spTelegramPhotoSize thumb)
    {
        _thumb = thumb;
    }

private:
    string _file_id;
    spTelegramPhotoSize _thumb;
    string _file_name;
    string _mime_type;
    int _file_size;
};


enum TelegramChatType {
    TPRIVATE = 1,
    TGROUP,
    TSUPERGROUP,
    TCHANNEL
};

class TelegramChat {
public:
    TelegramChat();

    TelegramChat(int id, TelegramChatType chat_type, const string& title, const string& username,
            const string& first_name, const string& last_name, bool all_members_are_administrators)
            :
            _id(id), _chat_type(chat_type), _title(title), _username(username), _first_name(first_name),
            _last_name(last_name), _all_members_are_administrators(all_members_are_administrators)
    {
    }

    TelegramChat(const TelegramChat&);

    virtual ~TelegramChat();

    bool
    IsAll_members_are_administrators() const
    {
        return _all_members_are_administrators;
    }

    void
    SetAll_members_are_administrators(bool all_members_are_administrators)
    {
        _all_members_are_administrators = all_members_are_administrators;
    }

    TelegramChatType
    GetChat_type() const
    {
        return _chat_type;
    }

    void
    SetChat_type(TelegramChatType chat_type)
    {
        _chat_type = chat_type;
    }

    string
    GetFirst_name() const
    {
        return _first_name;
    }

    void
    SetFirst_name(const string& first_name)
    {
        _first_name = first_name;
    }

    string
    GetLast_name() const
    {
        return _last_name;
    }

    void
    SetLast_name(const string& last_name)
    {
        _last_name = last_name;
    }

    string
    GetTitle() const
    {
        return _title;
    }

    void
    SetTitle(const string& title)
    {
        _title = title;
    }

    string
    GetUsername() const
    {
        return _username;
    }

    void
    SetUsername(const string& username)
    {
        _username = username;
    }

    int
    GetId() const
    {
        return _id;
    }

    void
    SetId(int id)
    {
        _id = id;
    }

private:
    // Уникальный идентификатор пользователя или бота
    int _id;
    TelegramChatType _chat_type;
    string _title;
    string _username;
    string _first_name;
    string _last_name;
    bool _all_members_are_administrators;
};


class TelegramUser {
public:
    TelegramUser();

    TelegramUser(int id, const string& first_name, const string& last_name, const string& username)
            :
            _id(id), _first_name(first_name), _last_name(last_name), _username(username)
    {
    }

    TelegramUser(const TelegramUser&);

    virtual ~TelegramUser();


    string
    GetFirst_name() const
    {
        return _first_name;
    }

    void
    SetFirst_name(const string& first_name)
    {
        _first_name = first_name;
    }

    int
    GetId() const
    {
        return _id;
    }

    void
    SetId(int id)
    {
        _id = id;
    }

    string
    GetLast_name() const
    {
        return _last_name;
    }

    void
    SetLast_name(const string& last_name)
    {
        _last_name = last_name;
    }

    string
    GetUsername() const
    {
        return _username;
    }

    void
    SetUsername(const string& username)
    {
        _username = username;
    }


private:
    // Уникальный идентификатор пользователя или бота
    int _id;

    // Имя бота или пользователя
    string _first_name;

    // Опционально. Фамилия бота или пользователя
    string _last_name;

    // Опционально. Username пользователя или бота
    string _username;
};


class TelegramCallbackQuery {
public:
    TelegramCallbackQuery();

    TelegramCallbackQuery(const string& id, spTelegramUser from, spTelegramMessage message,
            const string& inline_message_id, const string& data)
            :
            _id(id), _from(from), _message(message), _inline_message_id(inline_message_id), _data(data)
    {
    }

    TelegramCallbackQuery(const TelegramCallbackQuery&);

    virtual ~TelegramCallbackQuery();

    string
    GetData() const
    {
        return _data;
    }

    void
    SetData(const string& data)
    {
        _data = data;
    }

    spTelegramUser
    GetFrom() const
    {
        return _from;
    }

    void
    SetFrom(spTelegramUser from)
    {
        _from = from;
    }

    string
    GetId() const
    {
        return _id;
    }

    void
    SetId(const string& id)
    {
        _id = id;
    }

    string
    GetInline_message_id() const
    {
        return _inline_message_id;
    }

    void
    SetInlineMessageId(const string& _inline_message_id)
    {
        this->_inline_message_id = _inline_message_id;
    }

    spTelegramMessage
    GetMessage() const
    {
        return _message;
    }

    void
    SetMessage(spTelegramMessage message)
    {
        _message = message;
    }

private:
    string _id;
    spTelegramUser _from;
    spTelegramMessage _message;
    string _inline_message_id;
    string _data;
};


class TelegramChosenInlineResult {
public:
    TelegramChosenInlineResult();

    TelegramChosenInlineResult(const string& result_id, spTelegramUser from,
            spTelegramLocation location,
            const string& inline_message_id, const string& query);

    TelegramChosenInlineResult(const TelegramChosenInlineResult&);

    virtual ~TelegramChosenInlineResult();

    spTelegramUser GetFrom() const;

    void SetFrom(spTelegramUser from);

    string GetInlineMessageId() const;

    void SetInlineMessageId(const string& inline_message_id);

    spTelegramLocation GetLocation() const;

    void SetLocation(spTelegramLocation location);

    string GetQuery() const;

    void SetQuery(const string& query);

    string GetResultId() const;

    void SetResultId(const string& result_id);

private:
    string _result_id;
    spTelegramUser _from;
    spTelegramLocation _location;
    string _inline_message_id;
    string _query;
};


class TelegramInlineQuery {
public:
    TelegramInlineQuery();

    TelegramInlineQuery(const string& id, spTelegramUser from,
            spTelegramLocation location,
            const string& query, const string& offset);

    TelegramInlineQuery(const TelegramInlineQuery&);

    virtual ~TelegramInlineQuery();

    spTelegramUser GetFrom() const;

    void SetFrom(spTelegramUser from);

    string GetId() const;

    void SetId(const string& id);

    spTelegramLocation GetLocation() const;

    void SetLocation(spTelegramLocation location);

    string GetOffset() const;

    void SetOffset(const string& offset);

    string GetQuery() const;

    void SetQuery(const string& query);

private:
    string _id;
    spTelegramUser _from;
    spTelegramLocation _location;
    string _query;
    string _offset;
};


class TelegramMessageEntity {
public:
    TelegramMessageEntity();

    TelegramMessageEntity(const string& type, int offset, int length, const string& url)
            :
            _type(type), _offset(offset), _length(length), _url(url)
    {
    }

    TelegramMessageEntity(const TelegramMessageEntity&);

    virtual ~TelegramMessageEntity();

    int
    GetLength() const
    {
        return _length;
    }

    void
    SetLength(int _length)
    {
        this->_length = _length;
    }

    int
    GetOffset() const
    {
        return _offset;
    }

    void
    SetOffset(int offset)
    {
        _offset = offset;
    }

    const string&
    GetType() const
    {
        return _type;
    }

    void
    SetType(const string& type)
    {
        _type = type;
    }

    const string&
    GetUrl() const
    {
        return _url;
    }

    void
    SetUrl(const string& url)
    {
        _url = url;
    }

private:
    string _type;
    int _offset;
    int _length;
    string _url;
};

class TelegramMessage {
public:
    TelegramMessage();

    TelegramMessage(int message_id, spTelegramUser from, time_t date, spTelegramChat chat,
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
            int migrate_to_chat_id, int migrate_from_chat_id);

    TelegramMessage(const TelegramMessage& o);

    virtual ~TelegramMessage();

    spTelegramAudio GetAudio() const;

    void SetAudio(spTelegramAudio audio);

    string GetCaption() const;

    void SetCaption(const string& caption);

    bool IsChannelChatCreated() const;

    void SetChannelChatCreated(bool channel_chat_created);

    spTelegramChat GetChat() const;

    void SetChat(spTelegramChat _chat);

    spTelegramContact GetContact() const;

    void SetContact(spTelegramContact contact);

    time_t GetDate() const;

    void SetDate(time_t date);

    bool IsDeleteChatPhoto() const;

    void SetDeleteChatPhoto(bool delete_chat_photo);

    spTelegramDocument GetDocument() const;

    void SetDocument(spTelegramDocument document);

    vector<TelegramMessageEntity> GetEntities() const;

    void SetEntities(vector<TelegramMessageEntity> entities);

    time_t GetForwardDate() const;

    void SetForwardDate(time_t forward_date);

    spTelegramUser GetForwardFrom() const;

    void SetForwardFrom(spTelegramUser forward_from);

    spTelegramUser GetFrom() const;

    void SetFrom(spTelegramUser from);

    bool IsGroupChatCreated() const;

    void SetGroupChatCreated(bool group_chat_created);

    spTelegramUser GetLeftChatMember() const;

    void SetLeftChatMember(spTelegramUser left_chat_member);

    spTelegramLocation GetLocation() const;

    void SetLocation(spTelegramLocation location);

    int GetMessageId() const;

    void SetMessageId(int message_id);

    int GetMigrateFromChatId() const;

    void SetMigrateFromChatId(int migrate_from_chat_id);

    int GetMigrateToChatId() const;

    void SetMigrateToChatId(int migrate_to_chat_id);

    spTelegramUser GetNewChatMember() const;

    void SetNewChatMember(spTelegramUser new_chat_member);

    spVectorTelegramPhotoSize GetNewChatPhoto() const;

    void SetNewChatPhoto(spVectorTelegramPhotoSize new_chat_photo);

    string GetNewChatTitle() const;

    void SetNewChatTitle(const string& new_chat_title);

    spVectorTelegramPhotoSize GetPhoto() const;

    void SetPhoto(spVectorTelegramPhotoSize photo);

    spTelegramSticker GetSticker() const;

    void SetSticker(spTelegramSticker sticker);

    bool IsSupergroupChatCreated() const;

    void SetSupergroupChatCreated(bool supergroup_chat_created);

    string GetText() const;

    void SetText(const string& text);

    spTelegramVenue GetVenue() const;

    void SetVenue(spTelegramVenue venue);

    spTelegramVideo GetVideo() const;

    void SetVideo(spTelegramVideo video);

    spTelegramVoice GetVoice() const;

    void SetVoice(spTelegramVoice voice);

private:
    int _message_id;
    spTelegramUser _from;
    time_t _date;
    spTelegramChat _chat;
    spTelegramUser _forward_from;
    time_t _forward_date;
    string _text;
    vector<TelegramMessageEntity> _entities;
    spTelegramAudio _audio;
    spTelegramDocument _document;
    spVectorTelegramPhotoSize _photo;
    spTelegramSticker _sticker;
    spTelegramVideo _video;
    spTelegramVoice _voice;
    string _caption;
    spTelegramContact _contact;
    spTelegramLocation _location;
    spTelegramVenue _venue;
    spTelegramUser _new_chat_member;
    spTelegramUser _left_chat_member;
    string _new_chat_title;
    spVectorTelegramPhotoSize _new_chat_photo;
    bool _delete_chat_photo;
    bool _group_chat_created;
    bool _supergroup_chat_created;
    bool _channel_chat_created;
    int _migrate_to_chat_id;
    int _migrate_from_chat_id;
};


class TelegramWebhookUpdate {
public:
    TelegramWebhookUpdate();

    TelegramWebhookUpdate(uint32_t update_id, spTelegramMessage message, spTelegramInlineQuery inline_query,
            spTelegramChosenInlineResult chosen_inline_result, spTelegramCallbackQuery callback_query);

    TelegramWebhookUpdate(const TelegramWebhookUpdate&);

    virtual ~TelegramWebhookUpdate();

    spTelegramMessage
    GetMessage() const
    {
        return _message;
    }

    void SetMessage(spTelegramMessage message);

    uint32_t GetUpdateId() const;

    void SetUpdateId(uint32_t _update_id);

    spTelegramCallbackQuery GetCallbackQuery() const;

    void SetCallbackQuery(spTelegramCallbackQuery callback_query);

    spTelegramChosenInlineResult GetChosenInlineResult() const;

    void SetChosenInlineResult(spTelegramChosenInlineResult chosen_inline_result);

    spTelegramInlineQuery GetInlineQuery() const;

    void SetInlineQuery(spTelegramInlineQuery inline_query);

private:
    uint32_t _update_id;

    spTelegramMessage _message;
    spTelegramInlineQuery _inline_query;
    spTelegramChosenInlineResult _chosen_inline_result;
    spTelegramCallbackQuery _callback_query;
};


class TelegramAPI : public IBaseAPI {
public:
    TelegramAPI();

    TelegramAPI(const TelegramAPI& orig);

    virtual ~TelegramAPI();

    virtual void on_get_message(const RequestParamsMap& params, const string& query_string, char* buffUot) override;

    virtual void on_post_message(const RequestParamsMap& params, const string& post_data, const string& query_string,
            char* buffUot) override;

    virtual int setWebhook(const string& url) override;
};

#endif /* TELEGRAMAPI_H */
