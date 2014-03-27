#ifndef GAME_H
#define GAME_H
#include<QObject>
#include "map.h"
#include "dice.h"
#include "player.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QObject *parent,Player *player);
    void start();
    void stop();

private:
    Player *players;
    Player *active;
    Map map;
    Dice dice;
    int DiceValue;
    int rollDice();
    bool moveFigure(Figure *figure);
};

#endif // GAME_H
