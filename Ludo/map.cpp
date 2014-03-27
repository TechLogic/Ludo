#include "map.h"

Map::Map(QObject *parent):QObject(parent)
{
    w= new QWidget();
    layout=createGrid();
}


QGridLayout* Map::createGrid(){
    QGridLayout *layout = new QGridLayout();
   // w->setLayout(layout);


    return layout;
}




void Map::createField(Field * field,int x, int y){

    field->setPixmap(QPixmap(QString::fromUtf8(":/image/field")));
    field->setFixedSize(25,25);
    field->setScaledContents(true);
    layout->addWidget(field,x,y);
}

void Map::createHouse(QGridLayout * grid){

}

void Map::createSpecialPoints(QGridLayout * grid){

}
 Map::~Map(){delete w;
            }

 QGridLayout * Map::createMap(){
     int x=1,y=0;
     start= new Field(w);
     Field * field=start;

     //createField(field,0,0);
     for(int i=1;i<=41;i++){
         field->setNext(new Field(w));
         field=field->getNext();
         if(i<11)
             x++;
         else if(i>=11 && i<21)
             y++;
         else if(i>=21 && i<31)
             x--;
         else if(i>=31 && i<=41)
             y--;
        createField(field,x,y);
     }

     field->setNext(start);
     return layout;
}
