#include<QGraphicsView>
#include<QObject>

#ifndef FIGURE_H
#define FIGURE_H


class Figure : public QGraphicsView
{
public:
    Figure(QObject *parent);
    void move(int value);
private:
    const QObject* player;
    QObject* currentPos;
};

#endif // FIGURE_H
