#ifndef FIELD_H
#define FIELD_H
#include<QLabel>
#include<QObject>
#include<QWidget>

class Field : public QLabel
{
public:
    Field(QWidget *parent);
    QObject* containsFigure();
    Field* getNext();
private:
    QObject* figure;
    Field* next;
    int x;
    int y;
};

#endif // FIELD_H
