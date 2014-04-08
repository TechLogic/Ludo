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
     bool hasWon();
     Field* getEnd();
     Field *getHome();
     void setEnd(Field *field);
     void setHome(Field*field);
     void setFigures(QList<Figure *>figures);
     void setStart(QList<Field *> field);
     QList<Field*> getStart();
     bool hasFigure(Figure *figure);
      QList<Figure *> getFigures();
     int getNr();


private:
     //Figure** figures;



protected:
     QList<Figure*> figures;

     QList<Field*> start;
     Field* end;
     int figuresCount;
     Field* home;
     int nr;


};


#endif // PLAYER_H
