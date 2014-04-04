#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include "figure.h"
#include "field.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent,int figuresCount);
    void setFigureToStart();
    bool hasWon();
     Field* getEnd();
     Field *getHome();
     void setEnd(Field *field);
     void setHome(Field*field);
     void setFigures(Figure *figures);
     bool hasFigure(Figure *figure);


private:
     Figure* figures;
     Field* start;
     Field* end;
     int figuresCount;
     Field* home;


};


#endif // PLAYER_H
