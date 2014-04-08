#include "field.h"
Field::Field(QWidget *parent):QLabel(parent),next(NULL),x(0),y(0),figure(NULL){
}
 Field::~Field(){
    next=NULL;
}

int Field::getX(){
    return x;
}
void Field::setX(int x){
    this->x=x;
}

void Field::setY(int y){
    this->y=y;
}

int Field::getY(){
    return y;
}


Field* Field::getNext(){
    return next;
}

   QObject* Field::containsFigure(){
       return figure;
}

   void Field::setFigure(QObject *f) {

       figure =f;
   }

   void Field::removeFigure(){
    figure = NULL;
   }

   void Field::setNext(Field * field){
       if(this->next!=NULL){
           field->next=this->next;

       }

       this->next=field;

   }
