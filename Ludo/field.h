#ifndef FIELD_H
#define FIELD_H
#include<QGraphicsView>
#include<QObject>

class Field : public QGraphicsView
{
public:
    Field(QObject *parent);
    QObject* containsFigure();
    Field* getNext();
private:
    QObject* figure;
    Field* next;
    int x;
    int y;
};

#endif // FIELD_H
