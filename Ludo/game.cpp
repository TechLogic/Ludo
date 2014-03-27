#include "game.h"

Game::Game(QObject *parent, Player *player):QObject(parent),players(player),active(player),map(parent),dice(new Dice(parent)){
}




int Game::rollDice(){
    return dice.roll();
}

bool Game::moveFigure(Figure *figure){
    if(active->hasFigure(figure)){
       return figure->move(DiceValue);
    }else{
        return false;
    }

}
