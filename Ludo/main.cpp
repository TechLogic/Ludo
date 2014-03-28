#include "ludo.h"
#include "game.h"
int main(int argc, char *argv[])
{
    QObject parent;
    Game* game = new Game(&parent);
    game->start(argc,argv);
}
