#include "map.h"

Map::Map(QObject *parent):QObject(parent)
{

}


QGridLayout* Map::createGrid(){
    QGridLayout *layout = new QGridLayout();
   // w->setLayout(layout);
    return layout;
}




void Map::createField(Field * field,int x, int y){

    field->setPixmap(QPixmap(QString::fromUtf8(":/picture/FIELD")));
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
     int x=0,y=0;
     start= new Field(w);
     Field * field=start;


     for(int i=1;i<41;i++){
         field->next= new Field(w);
         field=field->next;
         if(i>10)
             x++;
         if(i>=10 && i<=21)
             y++;
         if(i>21 && i<=32)
             x--;
         if(i>32 && i<41)
             y--;
    createField(field,x,y);
     }
     return createGrid();
}
