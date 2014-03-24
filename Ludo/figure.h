#include<QLabel>
#include<QObject>
#include<QWidget>

#ifndef FIGURE_H
#define FIGURE_H


class Figure : public QLabel
{
public:
    Figure(QWidget *parent);
    void move(int value);
private:
    const QObject* player;
    QObject* currentPos;
};

#endif // FIGURE_H
