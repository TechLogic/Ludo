#include "game.h"

Game::Game(QObject *parent, Player *player):QObject(parent),map(parent),players(player),dice(new Dice(parent)){
}
