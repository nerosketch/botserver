#include <fmt/core.h>
#include "errors.h"
#include "user_inbox_message.h"

UserInboxMessage::UserInboxMessage() = default;

UserInboxMessage::UserInboxMessage(const nlohmann::json& json_dialog)
{
  from_json(json_dialog, *this);
}

UserInboxMessage::UserInboxMessage(const UserInboxMessage &o) = default;

UserInboxMessage::~UserInboxMessage() = default;

spUserInboxMessage UserInboxMessage::parseFromString(const string &data)
{
  json j;
  try
  {
    j = json::parse(data);
    auto parsed_inbox_message = j.get<UserInboxMessage>();

    auto sp_inbox_msg = make_shared<UserInboxMessage>(parsed_inbox_message);

    return sp_inbox_msg;
  }
  catch (json::parse_error &ex)
  {
    botserver::Error::sendError(
      fmt::format("ERROR: parse error at byte {}", ex.byte
    ));

    return nullptr;
  } catch (json::exception &ex)
  {
    botserver::Error::sendError(
      fmt::format("ERROR: json exception error: {}", ex.what())
    );
    return nullptr;
  }

  botserver::Error::sendError("ERROR: unextected error, end of UserInboxMessage::parseFromString function");
  return nullptr;
}
