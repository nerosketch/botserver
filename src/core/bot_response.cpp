#include <iostream>
#include "bot_response.h"

BotResponse::BotResponse() = default;

BotResponse::BotResponse(const string& text)
:text(text) {}

BotResponse::BotResponse(const string& text, const vector<Button>& buttons )
:text(text), buttons(buttons) {}

BotResponse::BotResponse(const BotResponse &o) = default;

BotResponse::~BotResponse() = default;

string BotResponse::getJsonString()
{
  DEBUG_STRUCT_LOG("BotResponse::getJsonString()");

  json j = *this;
  return j.dump();
}
