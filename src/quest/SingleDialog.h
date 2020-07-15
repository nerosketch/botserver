/*
 * File:   SingleDialog.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:56 PM
 */

#ifndef SINGLEDIALOG_H
#define SINGLEDIALOG_H

#include <vector>
#include <memory>
#include <string>
#include "../global_types.h"


class SingleDialog;

typedef std::shared_ptr<SingleDialog> spSingleDialog;


class GameButton {
public:
    GameButton();

    GameButton(const GameButton& orig);

    virtual ~GameButton();

    void onClick();

private:
    spSingleDialog target_dialog;
    std::string button_text;
    Color color;
};

typedef std::shared_ptr<GameButton> spGameButton;
typedef std::vector<spGameButton> GameButtons;


class SingleDialog {
public:
    SingleDialog();

    SingleDialog(const SingleDialog& orig);

    virtual ~SingleDialog();


private:
    GameButtons buttons;
};

#endif /* SINGLEDIALOG_H */
