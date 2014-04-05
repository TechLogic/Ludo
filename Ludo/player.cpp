#include <QObject>
#include "player.h"

Player::Player(QObject *parent,int figuresCount):QObject(parent),
    figuresCount(figuresCount),end(NULL),home(NULL),start(NULL),figures(NULL)
{

}

Figure* Player::getFigures(){
    return figures;
}

Field* Player::getEnd(){
    return end;
}

Field* Player::getHome(){
    return home;
}
void Player::setEnd(Field *field){
    this->end=field;
}

void Player::setHome(Field*field){
    this->home=field;
}

void Player::setFigures(Figure *figures){
    this->figures=figures;
}

bool Player::hasWon(){
    Field* begin = home;
    Field* end =  home +figuresCount-1;


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
    if( figuresCount==1 &&f == figure)
        return true;

        Figure* end = f +figuresCount-1;
        while(f < end){
        if(f == figure){
           return true;
       }
       f++;
    }
   return false;
}



