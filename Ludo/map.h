#ifndef MAP_H
#define MAP_H
#include <QObject>

class Map : public QObject
{
public:
    Map(QObject *parent);
    static Map* createMap(QObject *parent);
};

#endif // MAP_H
