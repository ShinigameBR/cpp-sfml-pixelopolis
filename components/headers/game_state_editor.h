#ifndef GAME_STATE_EDITOR_H
#define GAME_STATE_EDITOR_H

#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "game_state_start.h"
using namespace sf;

class GameStateEditor : public GameState
{
private:
    View gameView;
    View guiView;

public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game *game);
};

#endif