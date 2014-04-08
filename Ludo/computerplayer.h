#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
class ComputerPlayer : public Player
{
Q_OBJECT
public:


    ComputerPlayer(QObject *parent,int figuresCount,int nr);
    void play(int value);


private:
    int figureBehind(Figure * fig);
    int getFieldsToFin(Figure *fig);
    bool isStartFieldFomOther(Field *f);
   // Field *startHouse;

};

#endif // COMPUTERPLAYER_H
