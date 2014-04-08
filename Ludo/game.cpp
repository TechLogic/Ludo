#include "game.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>
#include "computerplayer.h"
#include <stdlib.h>
#include <unistd.h>
Game::Game(QObject *parent):QObject(parent),map(NULL),dice(new Dice(parent)),DiceValue(0),active(0)//,players(){
{}




int Game::rollDice(){
    return dice.roll();
}

void Game::moveFigureBack(Figure *figure){
    Field* newField = (Field*)(figure->getPositition());

    int newX = newField->getX();
    int newY = newField->getY();
    std::cout<<newX<<"/"<<newY<<std::endl;
    layout->removeWidget(figure);
     layout->addWidget(figure,newX,newY);
}

bool Game::move(Figure *figure){

    if(players[active]->hasFigure(figure)){
       bool result= figure->move(DiceValue);
       if(result == true){
       Field* newField = (Field*)(figure->getPositition());
       int newX = newField->getX();
       int newY = newField->getY();
        layout->removeWidget(figure);
        layout->addWidget(figure,newX,newY);
        figure->raise();
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
    diceButton= new QPushButton (&w);
    diceButton->setText("6");
    QObject::connect(diceButton,SIGNAL(clicked()),this,SLOT(throwDice()));


    map = new Map(this->parent());
    w.setMinimumSize(500,500);
    w.setWindowTitle(
    QApplication::translate("Ludo", "Ludo"));
    layout=map->createMap();
    layout->addWidget(diceButton,15,15);



    w.setLayout(layout);
    w.show();

    for(int a=0;a<2;a++){
        Player* p;
        if(a<1)
        p=new Player(&parent,4,a+1);
        else
            p= new ComputerPlayer(&parent,4,a+1);
        QList<Figure *>figures1=map->createStartHouse(p);
        foreach(Figure * fi, figures1){
             QObject::connect(fi,SIGNAL(clicked(Figure*)),this,SLOT(moveFigure(Figure*)));
             QObject::connect(fi,SIGNAL(moved(Figure*)),this,SLOT(moveFigureBack(Figure*)));
        }
        map->createEndHouseOfPlayer(p);
        players<<p;

}
    active=0;
    return a.exec();
}



void Game::showMove(Figure *figure){
    std::cout<<"Test"<<std::endl;
}


bool Game::FigureInEndHouse(Figure *figure){
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

    if(DiceValue==0)
        return;
std::cout<<"normal"<<std::endl;
    if(FigureInEndHouse(figure)){

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
        active = ++active % players.count();
        if(active == 0){
            active = 0;
            }
        }


    ComputerPlayer *p=dynamic_cast<ComputerPlayer*>(players[active]);
    if(p!=NULL ){
       // ComputerPlayer * player=players[active];
        //sleep(10);
std::cout<<"pc"<<std::endl;
         throwDice();
         //sleep(10);
        int i=0;
       /* for(i=0;i<4;i++){
           Figure *f=p->getFigures()[i];
           f=f;
        }*/
        p->play(DiceValue);
active = ++active % players.count();
    }

    }

}

bool Game::FigureInStartHouse(Figure *figure){

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



bool Game::hasThreeThrows(){

    QList<Figure *>figure =players[active]->getFigures();
int i=0;
while(figure.at(i) != NULL){
    if(FigureInEndHouse(figure.at(i))||FigureInStartHouse(figure.at(i))){
            //figure = figure++;
            i++;
        }else{
            return false;
        }
    }

    return true;


}

void Game::throwDice(){



    if(DiceValue %6 == 0){


        DiceValue += rollDice();
    }else{
        if(hasThreeThrows() && ThrowCount >3){
            DiceValue = 0;
            ThrowCount++;
        }

    }
diceButton->setText(QString::number(DiceValue));
    std::cout<<"l"<<DiceValue<<std::endl;
}

Game::~Game(){
   // delete &players;
   // delete diceButton;
}
