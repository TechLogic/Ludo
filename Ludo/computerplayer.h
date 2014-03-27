#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
class ComputerPlayer : public Player
{
Q_OBJECT
public:
    ComputerPlayer(QObject *parent);
    void play();
};

#endif // COMPUTERPLAYER_H
