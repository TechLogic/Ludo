#include "computerplayer.h"
#include "figure.h"
#include "field.h"

ComputerPlayer::ComputerPlayer(QObject *parent,int figuresCount): Player(parent,figuresCount)
{

}

void ComputerPlayer::play(int value){
   Figure* f = figures;
   Figure* best;

   if(value == 6){
       Field* field = startHouse;
       while(field!= NULL){
           if(field->containsFigure() != NULL){
               emit best->clicked(best);
               return;
           }else{
               field++;
           }
       }
   }
   best = f;
   while(f != NULL){
        Field* field = f->showMove(value);

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
                        homeField++;
                    }
                }
            }
        }

        f++;
    }

   }
