#ifndef MAP_H
#define MAP_H

class Map : public QObject
{
public:
    Map(QObject *parent);
    static Map* createMap(QObject *parent);
};

#endif // MAP_H
