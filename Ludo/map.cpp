#include "map.h"
#include "iostream"
#include <QVector>

Map::Map(QObject *parent):QObject(parent),startHousePoint({{13,1},{13,10},{0,10},{0,1}})
{
    w= new QWidget();
    layout=createGrid();
   // startHousePoint=

}


QGridLayout* Map::createGrid(){
    QGridLayout *layout = new QGridLayout();
   // w->setLayout(layout);


    return layout;
}

void Map::createEndHouseOfPlayer(Player *player){
    int nr=player->getNr();
    Field *field=endPoint[nr-1];
    int x=field->getY(),y=field->getX()+1;

    player->setEnd(field);

    field->setPixmap(QPixmap(QString::fromUtf8(":/image/field%1").arg(QString::number(nr))));
    for(int i=0;i<4;i++){

        if(i==0){

             field=new Field(w);
             player->setHome(field);
        }
        else{
            field->setNext(new Field(w));
            field=field->getNext();
        }

        createField(field,y,x);
        field->setPixmap(QPixmap(QString::fromUtf8(":/image/field%1").arg(QString::number(nr))));
        y++;

    }
}

Field * Map::getStartField(){
    //std::cout<<"map::  "<<start->text.toStdString()<<std::endl;
    return NULL;
}

 Figure * Map::getFigure(Player *player){
    Figure * figure= new Figure(w, player);
    int nr=player->getNr();
    figure->setPixmap(QPixmap(QString::fromUtf8(":/image/figure%1").arg(QString::number(nr))));
    figure->setFixedSize(25,25);
    figure->setScaledContents(true);

    return figure;
}

void Map::createField(Field * field,int x, int y){

    field->setPixmap(QPixmap(QString::fromUtf8(":/image/field")));
    field->setFixedSize(25,25);
    field->setScaledContents(true);
    field->setX(x);
    field->setY(y);
    layout->addWidget(field,x,y);

}

QList<Figure*>Map::createStartHouse(Player * pl){
    Field * house[4];
    for(int i=0;i<4;i++)
        house[i]=NULL;
    QList< Figure* >  figures;
     int  nr= pl->getNr();
    int x=startHousePoint[nr-1][0],y=startHousePoint[nr-1][1];
    for(int i=0;i<4;i++){
        house[i]=new Field(w);
        Figure *figure=this->getFigure(pl);

        if(i==2){
            x--;
            y++;
        }else
            x++;
        //figures[i]=getFigure(pl);
        createField(house[i],y,x);
        //char []text=":/image/field"+pl->getNr();

        //st.append(pl->getNr());
        house[i]->setPixmap(QPixmap(QString::fromUtf8(":/image/field%1").arg(QString::number(nr))));

        house[i]->setFigure(figure);
        figure->setPosition(house[i]);
        house[i]->setNext(startPoint[nr-1]);
        layout->addWidget(figure,y,x);
        figures<<figure;
    }
    startPoint[nr-1]->setPixmap(QPixmap(QString::fromUtf8(":/image/field%1").arg(QString::number(nr))));

    pl->setStart(house[0]);
    pl->setFigures(figures);
    return figures;


}


void Map::createSpecialPoints(QGridLayout * grid){

}
 Map::~Map(){delete w;
            // delete figures;
            }


 QGridLayout * Map::createMap(){
     int x=1,y=3;
     int currentStartPointCount=0;
     int currentEndPointCount=0;
     start= new Field(w);
     start->text="start";
std::cout<<start->text.toStdString()<<std::endl;
     Field * field=start;

     createField(field,x,y);
     for(int i=1;i<=41;i++){
         field->setNext(new Field(w));
         field=field->getNext();
         field->text="x,y";
         if(i<11)
             y++;
         else if(i>=11 && i<21)
             x++;
         else if(i>=21 && i<31)
             y--;
         else if(i>=31 && i<=40)
             x--;
         if(i==1 || i==10 || i==20 || i==30){
             if(i==1){
             startPoint[3]=field;
             }else{
                 startPoint[currentStartPointCount]=field;
             currentStartPointCount++;
             }
         }
         if(i==9 || i==19|| i==29 || i==39){
                      endPoint[currentEndPointCount]=field;
                      currentEndPointCount++;
                  }
        createField(field,x,y);
     }

     field->setNext(start);
     return layout;
}
