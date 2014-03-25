#include "figure.h"
#include <QObject>
#include"field.h"
Figure::Figure(QWidget *parent): QLabel(parent){

}

void Figure::move(int value){

    Field *field = (Field*) currentPos;
    for(int i = value;i>0;i--){
        if(field->getNext() != NULL){
            field = field->getNext();
        }else{
            field = NULL;
            break;
        }
    }
    if(field != NULL){
        ((Field*)currentPos)->removeFigure();
        field->setFigure(this);
        currentPos = field;
    }


}
