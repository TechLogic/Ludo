#include "game.h"

Game::Game(QObject *parent, Player *player):QObject(parent),players(player),active(player),map(new Map(parent)),dice(new Dice(parent)){
}




int Game::rollDice(){
    return dice.roll();
}

bool Game::move(Figure *figure){
    if(active->hasFigure(figure)){
       return figure->move(DiceValue);
    }else{
        return false;
    }

}


void Game::start(){
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
}
