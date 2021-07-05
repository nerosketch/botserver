#include <iostream>
#include "bot_response.h"

BotResponse::BotResponse() = default;

BotResponse::BotResponse(const string& text)
:text(text) {}

BotResponse::BotResponse(const string& text, const ButtonsType& buttons )
:text(text), buttons(buttons) {}

BotResponse::BotResponse(const BotResponse &o) = default;

BotResponse::~BotResponse() = default;

string BotResponse::getJsonString()
{
  DEBUG_STRUCT_LOG("BotResponse::getJsonString()");

  json j = *this;
  return j.dump();
}

spBotResponse BotResponse::makeResponse(const string& text)
{
  return make_shared<BotResponse>(text);
}

spBotResponse BotResponse::makeResponse(const string& text, const ButtonsType& buttons)
{
  return make_shared<BotResponse>(text, buttons);
}
