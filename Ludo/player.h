#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include "figure.h"
#include "field.h"

class Player : public QObject
{
public:
    Player(QObject *parent);
    int rollDice(Dice *dice);
    void moveFigure(const Figure* figure);
    void setFigureToStart();
    bool hasWon();
    Field* getEnd();
    Field* getHome();
private:
    const Figure figures[];
    const Field* start;
    const Field* end;
    const Field* home;


};


#endif // PLAYER_H
