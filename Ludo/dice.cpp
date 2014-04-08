#include "dice.h"
#include <ctime>

Dice::Dice(QObject *parent): QObject(parent){

}

int Dice::roll(){

    value =rand()%6+1;
    return value;
}

int Dice::getValue(){
    return value;
}
