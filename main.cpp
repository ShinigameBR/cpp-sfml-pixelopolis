#include "components/headers/game.h"
#include "components/headers/game_state_start.h"

int main()
{
    printf("teste");
    Game game;

    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}