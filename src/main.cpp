#include <Controller.h>
#include "Game.h"

int main()
{
    Game &game = Game::Instance();
  //Game game;
  game.start();
}