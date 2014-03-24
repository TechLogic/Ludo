#include "game.h"

Game::Game(QObject *parent, Player *player):QObject(parent),players(player),map(parent),dice(new Dice(parent)){
}
