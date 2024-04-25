#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "texture_manager.h"
using namespace std;
using namespace sf;

class GameState; // GameState e Game precisão saber da exisência um do outro.
class Game
{
private:
    void loadTextures();

public:
    stack<GameState *>
        states;

    RenderWindow window;
    TextureManager texmgr;
    Sprite background;

    void pushState(GameState *state);
    void popState();
    void changeState(GameState *state);
    GameState *peekState();

    void gameLoop();

    Game();
    ~Game();
};

#endif
