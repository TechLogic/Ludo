#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include "figure.h"
#include "field.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent);
    void setFigureToStart();
    bool hasWon();
     Field* getEnd();
     Field *getHome();

private:
    const Figure figures[];
     Field* start;
     Field* end;
     Field* home;


};


#endif // PLAYER_H
