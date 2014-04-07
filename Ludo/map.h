#ifndef MAP_H
#define MAP_H
#include <QObject>
#include<QGridLayout>
#include"field.h"
#include "figure.h"
#include "player.h"

using namespace std;

class Map : public QObject
{
    Q_OBJECT
public:
    Map(QObject *parent);
    static Map* createMap(QObject *parent);
    QGridLayout * createMap();
    Field * getStartField();
    Figure * getFigure(Player *player);
    void createEndHouseOfPlayer(Player *player);
    //start Field is next of StartHouse
    Figure **createStartHouse(Player * player);

    void createEndField(Player * player);

    ~Map();



private:
    //variablen
    QWidget * w;
    QGridLayout * layout;
    Field * startPoint [4];
    Field * endPoint [4];
    Field * start;

    QGridLayout* createGrid();
    Field * drawColumn(QGridLayout * grid, int x, int y);
    void drawRow(QGridLayout* grid ,int x, int y, int lenght);
    void createHouse(Player &pl);
    void createSpecialPoints(QGridLayout * grid);
    void createField(Field *field, int x, int y);


};

#endif // MAP_H
