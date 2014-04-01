#include "game.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>
Game::Game(QObject *parent):QObject(parent),map(NULL),dice(new Dice(parent)),DiceValue(0){
}




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
    QPushButton button("throw dice");
    QObject::connect(&button,SIGNAL(clicked()),this,SLOT(throwDice()));

    map = new Map(this->parent());
    w.setMinimumSize(500,500);
    w.setWindowTitle(
    QApplication::translate("Ludo", "Ludo"));
    layout=map->createMap();
    layout->addWidget(&button,12,12);
    Player pl(&parent,1);



    pl.setEnd(new Field(&w));
    pl.setHome(new Field(&w));
Figure * f=map->getFigure(&pl);
pl.setFigures(f);
    Field * fi=map->getStartField();


    fi->setFigure(f);

    w.setLayout(layout);
    w.show();


    f->setPosition(fi);

   // DiceValue=5;
    active=&pl;
    bool kp=move(f);

    return a.exec();
}



void Game::showMove(Figure *figure){

}


void Game::moveFigure(Figure *figure){

    bool result = move(figure);
    if(result == true){
        DiceValue = 0;
        active = active++;
    }
}

void Game::throwDice(){

    if(DiceValue %6 == 0){
        DiceValue = rollDice();
    }
    std::cout<<DiceValue<<std::endl;
}
