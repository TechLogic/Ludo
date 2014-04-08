#include "figure.h"
#include <QObject>
#include"field.h"
#include "player.h"
#include <QEvent>
#include<iostream>
Figure::Figure(QWidget *parent, QObject *player): QLabel(parent),player(player){

}


void Figure::mousePressEvent(QMouseEvent *ev){
    emit clicked(this);
  }

bool Figure::eventFilter(QObject *obj, QEvent *event){
     if(obj == this){
        if( event->type()==QEvent::Enter){
            emit enter(this);
            return true;
        }

        if(event->type()== QEvent::Leave){
            emit leave(this);
            return true;
        }
    }

}

QWidget* Figure::getPositition(){
    return currentPos;
}

QObject* Figure::getPlayer(){
    return player;
}


Field* Figure::showMove(int value){
    Field *field = (Field*) currentPos;
    Player *p = (Player*)player;
    Field *end =p->getEnd();
    for(int i = value;i>0;i--){

        if(field->getNext() == NULL){
            return NULL;
        }

        if(field != end){
            field = field->getNext();
        }else{
            field = p->getHome();
        }
    }
    return field;

}

bool Figure::move(int value){
       Field *field = showMove(value);
       if(field!= NULL){

           if(field->containsFigure()!=NULL){
            Figure* figure =(Figure*)field->containsFigure();
            std::cout<<figure->getPositition()<<std::endl;
            Player* p= (Player*)figure->getPlayer();
            Field* start= p->getStartHouse();
            while(start!= NULL){
                if(start->containsFigure()== NULL){
                    start->setFigure(figure);
                    std::cout<<start->getX()<<"/"<<start->getY()<<std::endl;
                    figure->setPosition(start);
                    emit figure->moved(figure);
                    break;
            }else{
                    start++;
                }
            }
           }
           ((Field*)currentPos)->removeFigure();
           field->setFigure(this);

        currentPos = field;
        return true;
}else{
        return false;
       }
}

void Figure::setPosition(QWidget *field){
    currentPos = field;
}
