#ifndef DICE_H
#define DICE_H
#include<QObject>
#include <cstdlib>


class Dice : public QObject
{
public:
    Dice(QObject *parent);
    int roll();
    int getValue();
private:
    int value;
};


#endif // DICE_H
