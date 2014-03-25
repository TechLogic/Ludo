#include<QLabel>
#include<QObject>
#include<QWidget>

#ifndef FIGURE_H
#define FIGURE_H


class Figure : public QLabel
{
public:
    Figure(QWidget *parent,QObject* player);
    bool move(int value);
    void setPosition(QWidget* field);
private:
    const QObject* player;
    QWidget* currentPos;
};

#endif // FIGURE_H
