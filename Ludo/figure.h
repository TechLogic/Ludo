#include<QLabel>
#include<QObject>
#include<QWidget>
#include "field.h"

#ifndef FIGURE_H
#define FIGURE_H


class Figure : public QLabel
{
    Q_OBJECT
public:
    Figure(QWidget *parent,QObject* player);
    bool move(int value);

    void setPosition(QWidget *field);


signals: void clicked(Figure*); void enter(Figure*); void leave(Figure*);

protected:
   void mousePressEvent(QMouseEvent *ev);
   bool eventFilter(QObject *obj, QEvent *event);
private:
    const QObject* player;
    QWidget* currentPos;
};

#endif // FIGURE_H
