#include <QObject>
#include "player.h"

Player::Player(QObject *parent):QObject(parent)
{
}

Field* Player::getEnd(){
    return end;
}

Field* Player::getHome(){
    return home;
}

bool Player::hasWon(){
    Field* begin = home;
    Field* end =  home + sizeof(figures)/sizeof(figures[0]);


    while ( begin < end ){
        if(begin->containsFigure()!= NULL){
        begin++;
        }else{
            return false;
        }
    }
    return true;

}

void Player::setFigureToStart(){

}

bool Player::hasFigure(Figure *figure){

    Figure* f = figures;
        Figure* end = f + sizeof(figures)/sizeof(figures[0]);
        while(f < end){
        if(f == figure){
           return true;
       }
       f++;
    }
   return false;
}



