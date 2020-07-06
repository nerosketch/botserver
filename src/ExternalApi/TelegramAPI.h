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


class TelegramPhotoSize
{
public:
  TelegramPhotoSize();

  TelegramPhotoSize (string _file_id, int _width, int _height, int _file_size) :
  _file_id (_file_id), _width (_width), _height (_height), _file_size (_file_size) { }

  TelegramPhotoSize(const TelegramPhotoSize&);
  virtual ~TelegramPhotoSize();

  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  int
  GetHeight () const
  {
    return _height;
  }

  void
  SetHeight (int _height)
  {
    this->_height = _height;
  }

  int
  GetWidth () const
  {
    return _width;
  }

  void
  SetWidth (int _width)
  {
    this->_width = _width;
  }

private:
  string _file_id;
  int _width;
  int _height;
  int _file_size;
};



class TelegramVideo
{
public:
  TelegramVideo();

  TelegramVideo (string _file_id, int _width, int _height, int _duration, spTelegramPhotoSize _thumb, string _mime_type, int _file_size) :
  _file_id (_file_id), _width (_width), _height (_height), _duration (_duration), _thumb (_thumb), _mime_type (_mime_type), _file_size (_file_size) { }

  TelegramVideo(const TelegramVideo&);
  virtual ~TelegramVideo();

  int
  GetDuration () const
  {
    return _duration;
  }

  void
  SetDuration (int _duration)
  {
    this->_duration = _duration;
  }

  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  int
  GetHeight () const
  {
    return _height;
  }

  void
  SetHeight (int _height)
  {
    this->_height = _height;
  }

  string
  GetMime_type () const
  {
    return _mime_type;
  }

  void
  SetMime_type (string _mime_type)
  {
    this->_mime_type = _mime_type;
  }

  spTelegramPhotoSize
  GetThumb () const
  {
    return _thumb;
  }

  void
  SetThumb (spTelegramPhotoSize _thumb)
  {
    this->_thumb = _thumb;
  }

  int
  GetWidth () const
  {
    return _width;
  }

  void
  SetWidth (int _width)
  {
    this->_width = _width;
  }

private:
  string _file_id;
  int _width;
  int _height;
  int _duration;
  spTelegramPhotoSize _thumb;
  string _mime_type;
  int _file_size;
};



class TelegramVoice
{
public:
  TelegramVoice();

  TelegramVoice (string _file_id, int _duration, string _mime_type, int _file_size) :
  _file_id (_file_id), _duration (_duration), _mime_type (_mime_type), _file_size (_file_size) { }

  TelegramVoice(const TelegramVoice&);
  virtual ~TelegramVoice();

  int
  GetDuration () const
  {
    return _duration;
  }

  void
  SetDuration (int _duration)
  {
    this->_duration = _duration;
  }

  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  string
  GetMime_type () const
  {
    return _mime_type;
  }

  void
  SetMime_type (string _mime_type)
  {
    this->_mime_type = _mime_type;
  }

private:
  string _file_id;
  int _duration;
  string _mime_type;
  int _file_size;
};




class TelegramContact
{
public:
  TelegramContact();

  TelegramContact (string _phone_number, string _first_name, string _last_name, int _user_id) :
  _phone_number (_phone_number), _first_name (_first_name), _last_name (_last_name), _user_id (_user_id) { }

  TelegramContact(const TelegramContact&);
  virtual ~TelegramContact();

  string
  GetFirst_name () const
  {
    return _first_name;
  }

  void
  SetFirst_name (string _first_name)
  {
    this->_first_name = _first_name;
  }

  string
  GetLast_name () const
  {
    return _last_name;
  }

  void
  SetLast_name (string _last_name)
  {
    this->_last_name = _last_name;
  }

  string
  GetPhone_number () const
  {
    return _phone_number;
  }

  void
  SetPhone_number (string _phone_number)
  {
    this->_phone_number = _phone_number;
  }

  int
  GetUser_id () const
  {
    return _user_id;
  }

  void
  SetUser_id (int _user_id)
  {
    this->_user_id = _user_id;
  }

private:
  string _phone_number;
  string _first_name;
  string _last_name;
  int _user_id;
};



class TelegramLocation
{
public:
  TelegramLocation();

  TelegramLocation (float _longitude, float latitude) :
  _longitude (_longitude), latitude (latitude) { }

  TelegramLocation(const TelegramLocation&);
  virtual ~TelegramLocation();

  float
  GetLongitude () const
  {
    return _longitude;
  }

  void
  SetLongitude (float _longitude)
  {
    this->_longitude = _longitude;
  }

  float
  GetLatitude () const
  {
    return latitude;
  }

  void
  SetLatitude (float latitude)
  {
    this->latitude = latitude;
  }

private:
  float _longitude;
  float latitude;
};



class TelegramVenue
{
public:
  TelegramVenue();

  TelegramVenue (spTelegramLocation _location, string _title, string _address, string _foursquare_id) :
  _location (_location), _title (_title), _address (_address), _foursquare_id (_foursquare_id) { }

  TelegramVenue(const TelegramVenue&);
  virtual ~TelegramVenue();

  string
  GetAddress () const
  {
    return _address;
  }

  void
  SetAddress (string _address)
  {
    this->_address = _address;
  }

  string
  GetFoursquare_id () const
  {
    return _foursquare_id;
  }

  void
  SetFoursquare_id (string _foursquare_id)
  {
    this->_foursquare_id = _foursquare_id;
  }

  spTelegramLocation
  GetLocation () const
  {
    return _location;
  }

  void
  SetLocation (spTelegramLocation _location)
  {
    this->_location = _location;
  }

  string
  GetTitle () const
  {
    return _title;
  }

  void
  SetTitle (string _title)
  {
    this->_title = _title;
  }

private:
  spTelegramLocation _location;
  string _title;
  string _address;
  string _foursquare_id;
};



class TelegramUserProfilePhotos
{
public:
  TelegramUserProfilePhotos();

  TelegramUserProfilePhotos (int _total_count, spVectorTelegramPhotoSize _photos) :
  _total_count (_total_count), _photos (_photos) { }

  TelegramUserProfilePhotos(const TelegramUserProfilePhotos&);
  virtual ~TelegramUserProfilePhotos();

  spVectorTelegramPhotoSize
  GetPhotos () const
  {
    return _photos;
  }

  void
  SetPhotos (spVectorTelegramPhotoSize _photos)
  {
    this->_photos = _photos;
  }

  int
  GetTotal_count () const
  {
    return _total_count;
  }

  void
  SetTotal_count (int _total_count)
  {
    this->_total_count = _total_count;
  }

private:
  int _total_count;
  spVectorTelegramPhotoSize _photos;
};



class TelegramSticker
{
public:
  TelegramSticker();

  TelegramSticker (string _file_id, int _width, int _height, spTelegramPhotoSize _thumb, int _file_size) :
  _file_id (_file_id), _width (_width), _height (_height), _thumb (_thumb), _file_size (_file_size) { }

  TelegramSticker(const TelegramSticker&);
  virtual ~TelegramSticker();

  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  int
  GetHeight () const
  {
    return _height;
  }

  void
  SetHeight (int _height)
  {
    this->_height = _height;
  }

  spTelegramPhotoSize
  GetThumb () const
  {
    return _thumb;
  }

  void
  SetThumb (spTelegramPhotoSize _thumb)
  {
    this->_thumb = _thumb;
  }

  int
  GetWidth () const
  {
    return _width;
  }

  void
  SetWidth (int _width)
  {
    this->_width = _width;
  }

private:
  string _file_id;
  int _width;
  int _height;
  spTelegramPhotoSize _thumb;
  int _file_size;
};


class TelegramAudio
{
public:
  TelegramAudio();

  TelegramAudio (string _file_id, int _duration, string _performer, string _title, string _mime_type, int _file_size) :
  _file_id (_file_id), _duration (_duration), _performer (_performer), _title (_title), _mime_type (_mime_type), _file_size (_file_size) { }

  TelegramAudio(const TelegramAudio&);
  virtual ~TelegramAudio();
  int
  GetDuration () const
  {
    return _duration;
  }

  void
  SetDuration (int _duration)
  {
    this->_duration = _duration;
  }

  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  string
  GetMime_type () const
  {
    return _mime_type;
  }

  void
  SetMime_type (string _mime_type)
  {
    this->_mime_type = _mime_type;
  }

  string
  GetPerformer () const
  {
    return _performer;
  }

  void
  SetPerformer (string _performer)
  {
    this->_performer = _performer;
  }

  string
  GetTitle () const
  {
    return _title;
  }

  void
  SetTitle (string _title)
  {
    this->_title = _title;
  }

private:
  string _file_id;
  int _duration;
  string _performer;
  string _title;
  string _mime_type;
  int _file_size;
};



class TelegramDocument
{
public:
  TelegramDocument();

  TelegramDocument (const string& file_id, spTelegramPhotoSize thumb, const string& file_name, const string& mime_type, int file_size) :
  _file_id (file_id), _thumb (thumb), _file_name (file_name), _mime_type (mime_type), _file_size (file_size) { }

  TelegramDocument(const TelegramDocument&);
  virtual ~TelegramDocument();
  
  string
  GetFile_id () const
  {
    return _file_id;
  }

  void
  SetFile_id (string _file_id)
  {
    this->_file_id = _file_id;
  }

  string
  GetFile_name () const
  {
    return _file_name;
  }

  void
  SetFile_name (string _file_name)
  {
    this->_file_name = _file_name;
  }

  int
  GetFile_size () const
  {
    return _file_size;
  }

  void
  SetFile_size (int _file_size)
  {
    this->_file_size = _file_size;
  }

  string
  GetMime_type () const
  {
    return _mime_type;
  }

  void
  SetMime_type (string _mime_type)
  {
    this->_mime_type = _mime_type;
  }

  spTelegramPhotoSize
  GetThumb () const
  {
    return _thumb;
  }

  void
  SetThumb (spTelegramPhotoSize _thumb)
  {
    this->_thumb = _thumb;
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
class TelegramChat
{
public:
  TelegramChat();

  TelegramChat (int id, TelegramChatType _chat_type, string _title, string _username, string _first_name, string _last_name, bool _all_members_are_administrators) :
  id (id), _chat_type (_chat_type), _title (_title), _username (_username), _first_name (_first_name), _last_name (_last_name), _all_members_are_administrators (_all_members_are_administrators) { }

  TelegramChat(const TelegramChat&);
  virtual ~TelegramChat();

  bool
  IsAll_members_are_administrators () const
  {
    return _all_members_are_administrators;
  }

  void
  SetAll_members_are_administrators (bool _all_members_are_administrators)
  {
    this->_all_members_are_administrators = _all_members_are_administrators;
  }

  TelegramChatType
  GetChat_type () const
  {
    return _chat_type;
  }

  void
  SetChat_type (TelegramChatType _chat_type)
  {
    this->_chat_type = _chat_type;
  }

  string
  GetFirst_name () const
  {
    return _first_name;
  }

  void
  SetFirst_name (string _first_name)
  {
    this->_first_name = _first_name;
  }

  string
  GetLast_name () const
  {
    return _last_name;
  }

  void
  SetLast_name (string _last_name)
  {
    this->_last_name = _last_name;
  }

  string
  GetTitle () const
  {
    return _title;
  }

  void
  SetTitle (string _title)
  {
    this->_title = _title;
  }

  string
  GetUsername () const
  {
    return _username;
  }

  void
  SetUsername (string _username)
  {
    this->_username = _username;
  }

  int
  GetId () const
  {
    return id;
  }

  void
  SetId (int id)
  {
    this->id = id;
  }
 
private:
  // Уникальный идентификатор пользователя или бота
   int id;
   TelegramChatType _chat_type;
   string _title;
   string _username;
   string _first_name;
   string _last_name;
   bool _all_members_are_administrators;
};



class TelegramUser
{
public:
  TelegramUser();

  TelegramUser (int id, string first_name, string last_name, string username) :
  id (id), first_name (first_name), last_name (last_name), username (username) { }

  TelegramUser(const TelegramUser&);
  virtual ~TelegramUser();
  
  
  string
  GetFirst_name () const
  {
    return first_name;
  }

  void
  SetFirst_name (string first_name)
  {
    this->first_name = first_name;
  }

  int
  GetId () const
  {
    return id;
  }

  void
  SetId (int id)
  {
    this->id = id;
  }

  string
  GetLast_name () const
  {
    return last_name;
  }

  void
  SetLast_name (string last_name)
  {
    this->last_name = last_name;
  }

  string
  GetUsername () const
  {
    return username;
  }

  void
  SetUsername (string username)
  {
    this->username = username;
  }

  
private:
  // Уникальный идентификатор пользователя или бота
  int id;

  // Имя бота или пользователя
  string first_name;
  
  // Опционально. Фамилия бота или пользователя
  string last_name;
  
  // Опционально. Username пользователя или бота
  string username;
};


class TelegramCallbackQuery
{
public:
  TelegramCallbackQuery();

  TelegramCallbackQuery (string id, spTelegramUser from, spTelegramMessage message, string inline_message_id, string data) :
  _id (id), _from (from), _message (message), _inline_message_id (inline_message_id), _data (data) { }

  TelegramCallbackQuery(const TelegramCallbackQuery&);
  virtual ~TelegramCallbackQuery();
  
  string
  GetData () const
  {
    return _data;
  }

  void
  SetData (string _data)
  {
    this->_data = _data;
  }

  spTelegramUser
  GetFrom () const
  {
    return _from;
  }

  void
  SetFrom (spTelegramUser _from)
  {
    this->_from = _from;
  }

  string
  GetId () const
  {
    return _id;
  }

  void
  SetId (string _id)
  {
    this->_id = _id;
  }

  string
  GetInline_message_id () const
  {
    return _inline_message_id;
  }

  void
  SetInline_message_id (string _inline_message_id)
  {
    this->_inline_message_id = _inline_message_id;
  }

  spTelegramMessage
  GetMessage () const
  {
    return _message;
  }

  void
  SetMessage (spTelegramMessage message)
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


class TelegramChosenInlineResult
{
public:
  TelegramChosenInlineResult();

  TelegramChosenInlineResult (string _result_id, spTelegramUser _from, spTelegramLocation _location, string _inline_message_id, string _query) :
  _result_id (_result_id), _from (_from), _location (_location), _inline_message_id (_inline_message_id), _query (_query) { }

  TelegramChosenInlineResult(const TelegramChosenInlineResult&);
  virtual ~TelegramChosenInlineResult();

  spTelegramUser
  GetFrom () const
  {
    return _from;
  }

  void
  SetFrom (spTelegramUser _from)
  {
    this->_from = _from;
  }

  string
  GetInline_message_id () const
  {
    return _inline_message_id;
  }

  void
  SetInline_message_id (string _inline_message_id)
  {
    this->_inline_message_id = _inline_message_id;
  }

  spTelegramLocation
  GetLocation () const
  {
    return _location;
  }

  void
  SetLocation (spTelegramLocation _location)
  {
    this->_location = _location;
  }

  string
  GetQuery () const
  {
    return _query;
  }

  void
  SetQuery (string _query)
  {
    this->_query = _query;
  }

  string
  GetResult_id () const
  {
    return _result_id;
  }

  void
  SetResult_id (string _result_id)
  {
    this->_result_id = _result_id;
  }

private:
  string _result_id;
  spTelegramUser _from;
  spTelegramLocation _location;
  string _inline_message_id;
  string _query;
};


class TelegramInlineQuery
{
public:
  TelegramInlineQuery();

  TelegramInlineQuery (string _id, spTelegramUser _from, spTelegramLocation _location, string _query, string _offset) :
  _id (_id), _from (_from), _location (_location), _query (_query), _offset (_offset) { }

  TelegramInlineQuery(const TelegramInlineQuery&);
  virtual ~TelegramInlineQuery();
  
private:
  string _id;
  spTelegramUser _from;
  spTelegramLocation _location;
  string _query;
  string _offset;

  spTelegramUser
  GetFrom () const
  {
    return _from;
  }

  void
  SetFrom (spTelegramUser _from)
  {
    this->_from = _from;
  }

  string
  GetId () const
  {
    return _id;
  }

  void
  SetId (string _id)
  {
    this->_id = _id;
  }

  spTelegramLocation
  GetLocation () const
  {
    return _location;
  }

  void
  SetLocation (spTelegramLocation _location)
  {
    this->_location = _location;
  }

  string
  GetOffset () const
  {
    return _offset;
  }

  void
  SetOffset (string _offset)
  {
    this->_offset = _offset;
  }

  string
  GetQuery () const
  {
    return _query;
  }

  void
  SetQuery (string _query)
  {
    this->_query = _query;
  }

};



class TelegramMessageEntity
{
public:
  TelegramMessageEntity();

  TelegramMessageEntity (string _type, int _offset, int _length, string _url) :
  _type (_type), _offset (_offset), _length (_length), _url (_url) { }

  TelegramMessageEntity(const TelegramMessageEntity&);
  virtual ~TelegramMessageEntity();
  
private:
  string _type;
  int _offset;

  int
  GetLength () const
  {
    return _length;
  }

  void
  SetLength (int _length)
  {
    this->_length = _length;
  }

  int
  GetOffset () const
  {
    return _offset;
  }

  void
  SetOffset (int _offset)
  {
    this->_offset = _offset;
  }

  string
  GetType () const
  {
    return _type;
  }

  void
  SetType (string _type)
  {
    this->_type = _type;
  }

  string
  GetUrl () const
  {
    return _url;
  }

  void
  SetUrl (string _url)
  {
    this->_url = _url;
  }

  int _length;
  string _url;
};

class TelegramMessage
{
public:
  TelegramMessage();

  TelegramMessage (int _message_id, spTelegramUser _from, time_t _date, spTelegramChat _chat, spTelegramUser _forward_from, time_t _forward_date, string _text, vector<TelegramMessageEntity> _entities, spTelegramAudio _audio, spTelegramDocument _document, spVectorTelegramPhotoSize _photo, spTelegramSticker _sticker, spTelegramVideo _video, spTelegramVoice _voice, string _caption, spTelegramContact _contact, spTelegramLocation _location, spTelegramVenue _venue, spTelegramUser _new_chat_member, spTelegramUser _left_chat_member, string _new_chat_title, spVectorTelegramPhotoSize _new_chat_photo, bool _delete_chat_photo, bool _group_chat_created, bool _supergroup_chat_created, bool _channel_chat_created, int _migrate_to_chat_id, int _migrate_from_chat_id) :
  _message_id (_message_id), _from (_from), _date (_date), _chat (_chat), _forward_from (_forward_from), _forward_date (_forward_date), _text (_text), _entities (_entities), _audio (_audio), _document (_document), _photo (_photo), _sticker (_sticker), _video (_video), _voice (_voice), _caption (_caption), _contact (_contact), _location (_location), _venue (_venue), _new_chat_member (_new_chat_member), _left_chat_member (_left_chat_member), _new_chat_title (_new_chat_title), _new_chat_photo (_new_chat_photo), _delete_chat_photo (_delete_chat_photo), _group_chat_created (_group_chat_created), _supergroup_chat_created (_supergroup_chat_created), _channel_chat_created (_channel_chat_created), _migrate_to_chat_id (_migrate_to_chat_id), _migrate_from_chat_id (_migrate_from_chat_id) { }

  TelegramMessage(const TelegramMessage&);
  virtual ~TelegramMessage();
  
  spTelegramAudio
  GetAudio () const
  {
    return _audio;
  }

  void
  SetAudio (spTelegramAudio _audio)
  {
    this->_audio = _audio;
  }

  string
  GetCaption () const
  {
    return _caption;
  }

  void
  SetCaption (string _caption)
  {
    this->_caption = _caption;
  }

  bool
  IsChannel_chat_created () const
  {
    return _channel_chat_created;
  }

  void
  SetChannel_chat_created (bool _channel_chat_created)
  {
    this->_channel_chat_created = _channel_chat_created;
  }

  spTelegramChat
  GetChat () const
  {
    return _chat;
  }

  void
  SetChat (spTelegramChat _chat)
  {
    this->_chat = _chat;
  }

  spTelegramContact
  GetContact () const
  {
    return _contact;
  }

  void
  SetContact (spTelegramContact _contact)
  {
    this->_contact = _contact;
  }

  time_t
  GetDate () const
  {
    return _date;
  }

  void
  SetDate (time_t _date)
  {
    this->_date = _date;
  }

  bool
  IsDelete_chat_photo () const
  {
    return _delete_chat_photo;
  }

  void
  SetDelete_chat_photo (bool _delete_chat_photo)
  {
    this->_delete_chat_photo = _delete_chat_photo;
  }

  spTelegramDocument
  GetDocument () const
  {
    return _document;
  }

  void
  SetDocument (spTelegramDocument _document)
  {
    this->_document = _document;
  }

  vector<TelegramMessageEntity>
  GetEntities () const
  {
    return _entities;
  }

  void
  SetEntities (vector<TelegramMessageEntity> _entities)
  {
    this->_entities = _entities;
  }

  time_t
  GetForward_date () const
  {
    return _forward_date;
  }

  void
  SetForward_date (time_t _forward_date)
  {
    this->_forward_date = _forward_date;
  }

  spTelegramUser
  GetForward_from () const
  {
    return _forward_from;
  }

  void
  SetForward_from (spTelegramUser _forward_from)
  {
    this->_forward_from = _forward_from;
  }

  spTelegramUser
  GetFrom () const
  {
    return _from;
  }

  void
  SetFrom (spTelegramUser _from)
  {
    this->_from = _from;
  }

  bool
  IsGroup_chat_created () const
  {
    return _group_chat_created;
  }

  void
  SetGroup_chat_created (bool _group_chat_created)
  {
    this->_group_chat_created = _group_chat_created;
  }

  spTelegramUser
  GetLeft_chat_member () const
  {
    return _left_chat_member;
  }

  void
  SetLeft_chat_member (spTelegramUser _left_chat_member)
  {
    this->_left_chat_member = _left_chat_member;
  }

  spTelegramLocation
  GetLocation () const
  {
    return _location;
  }

  void
  SetLocation (spTelegramLocation _location)
  {
    this->_location = _location;
  }

  int
  GetMessage_id () const
  {
    return _message_id;
  }

  void
  SetMessage_id (int _message_id)
  {
    this->_message_id = _message_id;
  }

  int
  GetMigrate_from_chat_id () const
  {
    return _migrate_from_chat_id;
  }

  void
  SetMigrate_from_chat_id (int _migrate_from_chat_id)
  {
    this->_migrate_from_chat_id = _migrate_from_chat_id;
  }

  int
  GetMigrate_to_chat_id () const
  {
    return _migrate_to_chat_id;
  }

  void
  SetMigrate_to_chat_id (int _migrate_to_chat_id)
  {
    this->_migrate_to_chat_id = _migrate_to_chat_id;
  }

  spTelegramUser
  GetNew_chat_member () const
  {
    return _new_chat_member;
  }

  void
  SetNew_chat_member (spTelegramUser _new_chat_member)
  {
    this->_new_chat_member = _new_chat_member;
  }

  spVectorTelegramPhotoSize
  GetNew_chat_photo () const
  {
    return _new_chat_photo;
  }

  void
  SetNew_chat_photo (spVectorTelegramPhotoSize _new_chat_photo)
  {
    this->_new_chat_photo = _new_chat_photo;
  }

  string
  GetNew_chat_title () const
  {
    return _new_chat_title;
  }

  void
  SetNew_chat_title (string _new_chat_title)
  {
    this->_new_chat_title = _new_chat_title;
  }

  spVectorTelegramPhotoSize
  GetPhoto () const
  {
    return _photo;
  }

  void
  SetPhoto (spVectorTelegramPhotoSize _photo)
  {
    this->_photo = _photo;
  }

  spTelegramSticker
  GetSticker () const
  {
    return _sticker;
  }

  void
  SetSticker (spTelegramSticker _sticker)
  {
    this->_sticker = _sticker;
  }

  bool
  IsSupergroup_chat_created () const
  {
    return _supergroup_chat_created;
  }

  void
  SetSupergroup_chat_created (bool _supergroup_chat_created)
  {
    this->_supergroup_chat_created = _supergroup_chat_created;
  }

  string
  GetText () const
  {
    return _text;
  }

  void
  SetText (string _text)
  {
    this->_text = _text;
  }

  spTelegramVenue
  GetVenue () const
  {
    return _venue;
  }

  void
  SetVenue (spTelegramVenue _venue)
  {
    this->_venue = _venue;
  }

  spTelegramVideo
  GetVideo () const
  {
    return _video;
  }

  void
  SetVideo (spTelegramVideo _video)
  {
    this->_video = _video;
  }

  spTelegramVoice
  GetVoice () const
  {
    return _voice;
  }

  void
  SetVoice (spTelegramVoice _voice)
  {
    this->_voice = _voice;
  }

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


class TelegramWebhookUpdate
{
public:
  TelegramWebhookUpdate();

  TelegramWebhookUpdate (uint32_t _update_id, spTelegramMessage _message, spTelegramInlineQuery _inline_query, spTelegramChosenInlineResult _chosen_inline_result, spTelegramCallbackQuery _callback_query) :
  _update_id (_update_id), _message (_message), _inline_query (_inline_query), _chosen_inline_result (_chosen_inline_result), _callback_query (_callback_query) { }

  TelegramWebhookUpdate(const TelegramWebhookUpdate&);
  virtual ~TelegramWebhookUpdate();


  spTelegramMessage
  GetMessage () const
  {
    return _message;
  }

  void
  SetMessage (spTelegramMessage _message)
  {
    this->_message = _message;
  }

  uint32_t
  GetUpdate_id () const
  {
    return _update_id;
  }

  void
  SetUpdate_id (uint32_t _update_id)
  {
    this->_update_id = _update_id;
  }

  spTelegramCallbackQuery
  GetCallback_query () const
  {
    return _callback_query;
  }

  void
  SetCallback_query (spTelegramCallbackQuery callback_query)
  {
    _callback_query = callback_query;
  }

  spTelegramChosenInlineResult
  GetChosen_inline_result () const
  {
    return _chosen_inline_result;
  }

  void
  SetChosen_inline_result (spTelegramChosenInlineResult chosen_inline_result)
  {
    _chosen_inline_result = chosen_inline_result;
  }

  spTelegramInlineQuery
  GetInline_query () const
  {
    return _inline_query;
  }

  void
  SetInline_query (spTelegramInlineQuery inline_query)
  {
    _inline_query = inline_query;
  }

private:
  uint32_t _update_id;

  spTelegramMessage _message;
  spTelegramInlineQuery _inline_query;
  spTelegramChosenInlineResult _chosen_inline_result;
  spTelegramCallbackQuery _callback_query;
};



class TelegramAPI : public IBaseAPI
{
public:
  TelegramAPI ();
  TelegramAPI (const TelegramAPI& orig);
  virtual ~TelegramAPI ();

  virtual void on_get_message(const RequestParamsMap& params, const string& query_string, char *buffUot) override;
  virtual void on_post_message(const RequestParamsMap& params, const string& post_data, const string& query_string, char *buffUot) override;

  int setWebhook(const string& url);
};

#endif /* TELEGRAMAPI_H */
