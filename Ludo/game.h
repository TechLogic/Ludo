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
    Game(QObject *parent);
    int start(int argc, char *argv[]);
    void stop();

    public slots:  void throwDice();
                   void showMove(Figure* figure);
                   void moveFigure(Figure* figure);

private:
    Player *players;
    Player *active;
    Map* map;
    QGridLayout* layout;
    Dice dice;
    int DiceValue;
    int rollDice();
    bool move(Figure *figure);
    void connectFigures();
    bool FigureInHouse(Figure* figure);
};

#endif // GAME_H
