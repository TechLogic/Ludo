#ifndef GAME_H
#define GAME_H
#include<QObject>
#include "map.h"
#include "dice.h"
#include "player.h"

class Game : public QObject
{
public:
    Game(QObject *parent,Player *player);
    void start();
    void stop();
private:
    Player *players;
    Map map;
    Dice dice;
};

#endif // GAME_H
