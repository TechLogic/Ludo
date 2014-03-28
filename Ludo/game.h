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

    public slots:  void throwDice();
                   void showMove(Figure* figure);
                   void moveFigure(Figure* figure);

private:
    Player *players;
    Player *active;
    Map map;
    Dice dice;
    int DiceValue;
    int rollDice();
    bool move(Figure *figure);
};

#endif // GAME_H
