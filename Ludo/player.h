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
private:
    const Figure figures[];
    const Field* start;
    const Field* end;


};


#endif // PLAYER_H
