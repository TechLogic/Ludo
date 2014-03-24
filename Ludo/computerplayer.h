#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
class ComputerPlayer : public Player
{
public:
    ComputerPlayer(QObject *parent);
    void play();
};

#endif // COMPUTERPLAYER_H
