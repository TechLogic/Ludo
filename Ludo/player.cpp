#include <QObject>
#include "player.h"

Player::Player(QObject *parent,int figuresCount):QObject(parent),
    figuresCount(figuresCount),end(NULL),home(NULL),start(NULL)//,figures(NULL)
{

}

 Player::~Player(){
     delete figures;
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

void Player::setStart(Field *field){
    this->start=field;
}

void Player::setFigures(Figure **figures ){
    for(int i=0;i<4;i++)
        this->figures[i]=figures[i];
    //this->figures=figures;
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

   // Figure* f [4];
    //f=figures;
    if( figuresCount==1 && figures[0] == figure)
        return true;
int i=0;
       // Figure* end = f+figuresCount-1;
       // while(f < end){
        for(i=0;i<4;i++){
            Figure * fi=figures[i];
            if( fi== figure){
           return true;
       }
      // f++;
    }
   return false;
}



