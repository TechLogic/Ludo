#include "ludo.h"
#include "game.h"
#include<time.h>
int main(int argc, char *argv[])
{
    QObject parent;
    srand(time(NULL));
    Game* game = new Game(&parent);
    game->start(argc,argv);
}
