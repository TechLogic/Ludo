#include "field.h"
Field::Field(QWidget *parent):QLabel(parent),next(NULL){
}
 Field::~Field(){
    next=NULL;
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
