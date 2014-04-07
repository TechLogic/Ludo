#include "game.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>
Game::Game(QObject *parent):QObject(parent),map(NULL),dice(new Dice(parent)),DiceValue(0)//,players(){
{}




int Game::rollDice(){
    return dice.roll();
}

bool Game::move(Figure *figure){

    if(active->hasFigure(figure)){
       bool result= figure->move(DiceValue);
       if(result == true){
       Field* newField = (Field*)(figure->getPositition());
       int newX = newField->getX();
       int newY = newField->getY();
        layout->removeWidget(figure);
        layout->addWidget(figure,newX,newY);
       }
        return result;
    }else{
        return false;
    }

}



int Game::start(int argc, char *argv[]){
    QObject parent;
    QApplication a(argc,argv);

    QWidget w;
    QPushButton button("6");
    button.setText("6");
    QObject::connect(&button,SIGNAL(clicked()),this,SLOT(throwDice()));


    map = new Map(this->parent());
    w.setMinimumSize(500,500);
    w.setWindowTitle(
    QApplication::translate("Ludo", "Ludo"));
    layout=map->createMap();
    layout->addWidget(&button,15,15);
    /*Player * pl[2];
    pl[0]=new Player(&parent,4,1);
    pl[1]=new Player(&parent,4,2);*/
    //players=new Player[2];
    Player pl(&parent,4,1);
//Figure **figures;

    w.setLayout(layout);
    w.show();
    int i=0;
    Figure **figures=map->createStartHouse(&pl);
    for(i=0;i<4;i++)
        QObject::connect(figures[i],SIGNAL(clicked(Figure*)),this,SLOT(moveFigure(Figure*)));
    map->createEndHouseOfPlayer(&pl);
    active=&pl;
   // active=pli[0];
Player plo(&parent,4,2);
Figure **figures1=map->createStartHouse(&plo);
for(i=0;i<4;i++)
    QObject::connect(figures1[i],SIGNAL(clicked(Figure*)),this,SLOT(moveFigure(Figure*)));
map->createEndHouseOfPlayer(&plo);
    return a.exec();
}



void Game::showMove(Figure *figure){

}


bool Game::FigureInHouse(Figure *figure){
    return false;
    Player* player=(Player*)figure->getPlayer();
    Field* startHouse = player->getHome();
    while(startHouse != NULL){
        if (startHouse->containsFigure() == figure){
           return true;
        }else{
            startHouse++;
        }
    }
    return false;
}


void Game::moveFigure(Figure *figure){



    if(FigureInHouse(figure)){

       // if(((Player*)figure->getPlayer())->getHome()->getNext()->containsFigure() == NULL){
        //       return;
       // }

        if(DiceValue ==6){
            DiceValue=1;
            moveFigure(figure);
        }else{
            return;
       }
    }else{
    bool result = move(figure);
    if(result == true){
        DiceValue = 0;
        active = active++;
        if(active == NULL){
            active = player;
            }
        }
    }
}

void Game::throwDice(){

    if(DiceValue %6 == 0){
        DiceValue += rollDice();
    }

    std::cout<<DiceValue<<std::endl;
}

Game::~Game(){
    //delete players;
}
