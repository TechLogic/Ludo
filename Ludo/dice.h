#ifndef DICE_H
#define DICE_H

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
