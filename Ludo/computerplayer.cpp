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

   if(value == 6){
       //Field* field = startHouse;
       foreach(Field *field,start){
           if(field->containsFigure() != NULL){

               best = (Figure*)field->containsFigure();

               emit best->clicked(best);
               return;
           }
       }
   }
   best = f.at(0);
   int i=0;
   //while(f.at(i) != NULL){
   foreach(Figure *fi,figures){
       best = fi;
        Field* field = fi->showMove(value);
       // best=fi;
        if(field != NULL){
            if(field->containsFigure() != NULL){
                best = (Figure*) field->containsFigure();
                emit best->clicked(best);
            }else{
                Field* homeField = home;
                while(homeField != NULL){
                    if(field == homeField|| field == end){
                        best = (Figure*) field->containsFigure();
                        emit best->clicked(best);
                        return;
                    }else{
                        homeField=homeField->getNext();
                    }
                }
            }
        }

       // i++;
    }
    int fig =rand()%4;
    std::cout<<"fig:"<<fig<<std::endl;

    emit figures[fig]->clicked(figures[fig]);
   }



