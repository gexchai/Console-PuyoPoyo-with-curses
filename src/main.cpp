#include "Game.h"

int main(int argc, char** argv) {
    Game *g = new Game();
    g->initGame();
    g->play();
    delete g;
}
