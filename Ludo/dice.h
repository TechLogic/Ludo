#ifndef DICE_H
#define DICE_H
#include<QObject>
#include <cstdlib>


class Dice : public QObject
{
Q_OBJECT
public:
    Dice(QObject *parent);
    int roll();
    int getValue();
private:
    int value;
};


#endif // DICE_H
