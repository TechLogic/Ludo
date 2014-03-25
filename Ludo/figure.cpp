#include "figure.h"
#include <QObject>
#include"field.h"
#include "player.h"
Figure::Figure(QWidget *parent, QObject *player): QLabel(parent),player(player){

}

bool Figure::move(int value){

    Field *field = (Field*) currentPos;
    Player *p = (Player*)player;
    Field *end =p->getEnd();
    for(int i = value;i>0;i--){

        if(field->getNext() == NULL){
            return false;
        }

        if(&field->getNext() != &end){
            field = field->getNext();
        }else{
            field = p->getHome();
        }
    }

    ((Field*)currentPos)->removeFigure();
        field->setFigure(this);
        currentPos = field;
    return true;
}
