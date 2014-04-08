#include "game.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>
#include "computerplayer.h"
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

    QPushButton* Next= new QPushButton (&w);
    Next->setText("Next Player");
    QObject::connect(Next,SIGNAL(clicked()),this,SLOT(nextPlayer()));



    map = new Map(this->parent());
    w.setMinimumSize(500,500);
    w.setWindowTitle(
    QApplication::translate("Ludo", "Ludo"));
    layout=map->createMap();
    layout->addWidget(diceButton,15,15);
    layout->addWidget(Next,16,15);



    w.setLayout(layout);
    w.show();

    for(int a=0;a<4;a++){
        Player* p;

        p=new Player(&parent,4,a+1);

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



    if(FigureInStartHouse(figure)){
        std::cout<< DiceValue<<std::endl;
           if(DiceValue ==6){
            std::cout<<"IN START HOUSE"<<std::endl;
            DiceValue=1;
            move(figure);
            DiceValue = 0;
        }else{
            return;
       }
    }else{
    bool result = move(figure);
    if(result == true){

        if(DiceValue != 6){
        DiceValue = 0;
        active = ++active % players.count();
        if(active == 0){
            active = 0;
            }
        }else{
            DiceValue =0;
        }
    }

    if(players[active]->inherits("ComputerPlayer") ){
        ComputerPlayer * player=(ComputerPlayer*)players[active];
        throwDice();
        player->play(DiceValue);

    }

    }
}

bool Game::FigureInStartHouse(Figure *figure){

    Player* player=(Player*)figure->getPlayer();
    QList<Field*> startHouse = player->getStart();
    foreach(Field* f,startHouse){
        if (f->containsFigure() == figure){
           return true;
        }
    }
    return false;
}



bool Game::hasThreeThrows(){

    QList<Figure *>figure =players[active]->getFigures();
int i=0;
foreach (Figure* f, figure) {

  if(FigureInEndHouse(f)||FigureInStartHouse(f)){
      }else{
            return false;
        }
    }


    return true;


}

void Game::nextPlayer(){
    active = ++active%players.count();
    ThrowCount = 0;
    DiceValue = 0;
    std::cout<<"NEXT PLAYER"<<std::endl;
}

void Game::throwDice(){



    if(DiceValue == 0){
      DiceValue += rollDice();
      diceButton->setText(QString::number(DiceValue));
      std::cout<<DiceValue<<std::endl;
    }
            if(hasThreeThrows() && ThrowCount <2){
                if(DiceValue != 6){
                DiceValue = 0;
                ThrowCount++;
                }

            }

    }


Game::~Game(){
   // delete &players;
   // delete diceButton;
}
