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
    std::mt19937 * generator;
    std::uniform_int_distribution<int> * distribution;
    //auto dice();
};


#endif // DICE_H
