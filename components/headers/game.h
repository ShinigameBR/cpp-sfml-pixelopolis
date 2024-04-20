#ifndef GAME_H
#define GAME_H
 
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

class GameState; //GameState e Game precisão saber da exisência um do outro.
class Game
{
    public:
 
    stack<GameState*> states;
 
    RenderWindow window;
 
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();
 
    void gameLoop();
 
    Game();
    ~Game();
};

#endif
