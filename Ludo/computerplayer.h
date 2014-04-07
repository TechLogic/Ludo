#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
class ComputerPlayer : public Player
{
Q_OBJECT
public:
    ComputerPlayer(QObject *parent, int figuresCount, int nr);
    void play();
private:
    int figureBehind(Figure * fig);
    int getFieldsToFin(Figure *fig);
    bool isStartFieldFomOther(Field *f);

};

#endif // COMPUTERPLAYER_H
