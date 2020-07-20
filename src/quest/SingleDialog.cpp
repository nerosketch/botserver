/*
 * File:   SingleDialog.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:56 PM
 */

#include "SingleDialog.h"

SingleDialog::SingleDialog() :
        buttons()
{
}

SingleDialog::SingleDialog(const SingleDialog& o) = default;

SingleDialog::~SingleDialog() = default;


void SingleDialog::SerializeMe(std::istream& in)
{
    // TODO: make it
}

void SingleDialog::DeserializeMe(std::ostream& out)
{
    // TODO: make it
}


GameButton::GameButton() :
        target_dialog(), button_text(), color()
{
}

GameButton::GameButton(const GameButton& o) = default;

GameButton::~GameButton() = default;


void GameButton::onClick()
{
}
