#ifndef FIELD_H
#define FIELD_H
#include<QLabel>
#include<QObject>
#include<QWidget>

class Field : public QLabel
{
    Q_OBJECT
public:
    Field(QWidget *parent);
    ~Field();
    QObject* containsFigure();
    Field* getNext();
    void setNext(Field *field);
    void setFigure(QObject* f);
    void removeFigure();
private:
    QObject* figure;
    Field* next;
    int x;
    int y;
};

#endif // FIELD_H
