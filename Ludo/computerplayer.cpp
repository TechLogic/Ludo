#include "computerplayer.h"
#include "figure.h"
#include "field.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
ComputerPlayer::ComputerPlayer(QObject *parent,int figuresCount,int nr): Player(parent,figuresCount,nr)
{

}

void ComputerPlayer::play(int value){
   QList<Figure*> f = figures;
   Figure* best;


   if(start[0]->getNext()->containsFigure()!=NULL){
       best=(Figure *)start[0]->getNext()->containsFigure();
       emit best->clicked(best);
       return;
   }
   if(value == 6  ){
       foreach(Field *field,start){
           if(field->containsFigure() != NULL){

               best = (Figure*)field->containsFigure();
               emit best->clicked(best);
               moveableFigures<<best;
               return;
           }
       }
   }

  if(allFiguresInStartHouse())
      return;

  foreach(Figure *f , moveableFigures){
      Field * field=f->showMove(value);
      Figure * figure=(Figure *)field->containsFigure();
      if(figure!=NULL && !moveableFigures.contains(figure)){
          emit figure->clicked(figure);
          return;
      }
  }
  bool canMoveSteps=false;
  int fig=0;
  while(!canMoveSteps){
     fig =rand()%moveableFigures.count();
     if(moveableFigures[fig]->showMove(value)!=NULL)
         canMoveSteps=true;
  }



    emit moveableFigures[fig]->clicked(moveableFigures[fig]);
   }



