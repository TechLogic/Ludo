#include <QObject>
#include "player.h"

Player::Player(QObject *parent, int figuresCount, int nr):QObject(parent),
    figuresCount(figuresCount),end(NULL),home(NULL),start(NULL),nr(nr)//,figures(NULL)
{

}

 Player::~Player(){
     delete &figures;
 }

QList<Figure *> Player::getFigures(){
    return figures;
}


Field* Player::getEnd(){
    return end;
}
int Player::getNr(){
    return nr;
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

void Player::setFigures(QList<Figure *> figures ){
    foreach(Figure * fi,figures)
        this->figures<<fi;
   // this->figures=figures;
}

Field* Player::getStartHouse(){
    return start;
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


bool Player::hasFigure(Figure *figure){

   // Figure* f [4];
    //f=figures;
    if( figuresCount==1 && figures.at(0) == figure)
        return true;
       // Figure* end = f+figuresCount-1;
       // while(f < end){
        foreach(Figure * fi, this->figures){

            if( fi== figure){
           return true;
       }
      // f++;
    }
   return false;
}



