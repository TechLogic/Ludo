#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

class ComputerPlayer : public Player
{
public:
    ComputerPlayer(QObject *parent);
    play();
};

#endif // COMPUTERPLAYER_H
