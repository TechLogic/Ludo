#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include "figure.h"
#include "field.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent,int figuresCount,int nr);
     ~Player();
    void setFigureToStart();
    bool hasWon();
     Field* getEnd();
     Field *getHome();
     void setEnd(Field *field);
     void setHome(Field*field);
     void setFigures(Figure **figures);
     void setStart(Field *field);
     bool hasFigure(Figure *figure);
     int getNr();


private:
     Figure** figures;
     Field* start;
     Field* end;
     int figuresCount;
     Field* home;
     int nr;


};


#endif // PLAYER_H
