#include "field.h"
Field::Field(QWidget *parent):QLabel(parent){
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
