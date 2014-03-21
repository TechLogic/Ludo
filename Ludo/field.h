#ifndef FIELD_H
#define FIELD_H

class Field : public QGraphicsView
{
public:
    Field(QObject *parent);
    Figure* containsFigure();
    Field* getNext();
private:
    Figure* figure;
    Field* next;
    int x;
    int y;
};

#endif // FIELD_H
