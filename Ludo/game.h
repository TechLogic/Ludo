#ifndef GAME_H
#define GAME_H

class Game : public QObject
{
public:
    Game(QObject *parent);
    start();
    stop();
private:
    Player players[];
    Map map;
    Dice dice;
};

#endif // GAME_H
