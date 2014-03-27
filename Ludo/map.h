#ifndef MAP_H
#define MAP_H
#include <QObject>
#include<QGridLayout>
#include"field.h"
class Map : public QObject
{
public:
    Map(QObject *parent);
    static Map* createMap(QObject *parent);
    QGridLayout * createMap();
    ~Map();



private:
    //variablen
    //QApplication a(argc, argv);
    QWidget * w;
    QGridLayout * layout;
    int player;
    Field * start;
    //methods
    QGridLayout* createGrid();
    Field * drawColumn(QGridLayout * grid, int x, int y);
    void drawRow(QGridLayout* grid ,int x, int y, int lenght);
    void createHouse(QGridLayout * grid);
    void createSpecialPoints(QGridLayout * grid);
    void createField(Field *field, int x, int y);


};

#endif // MAP_H
