#include "computerplayer.h"
#include "figure.h"
#include "field.h"

ComputerPlayer::ComputerPlayer(QObject *parent,int figuresCount,int nr): Player(parent,figuresCount,nr)
{

}

void ComputerPlayer::play(int value){
   QList<Figure*> f = figures;
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
   best = f.at(0);
   int i=0;
   //while(f.at(i) != NULL){
   for(i=0;i<f.count();i++){
        Field* field = f.at(i)->showMove(value);

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

       // i++;
    }

   }
