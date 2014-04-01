#include "dice.h"
#include <ctime>

Dice::Dice(QObject *parent): QObject(parent){
    //std::random_device rd;
    //generator= new std::mt19937();
    //distribution=new std::uniform_int_distribution<int> (1,6);
    //dice = std::bind ( distribution, generator );
}

int Dice::roll(){
   // std::uniform_int_distribution<int> dist(1, 6);
    value =rand()%6+1;
    return value;
}

int Dice::getValue(){
    return value;
}
