#ifndef GAME_STATE_START_H
#define GAME_STATE_START_H

#include "game_state.h"
#include "game_state_editor.h"
using namespace sf;

class GameStateStart : public GameState
{
private:
    View view;
    void loadgame();

public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateStart(Game *game);
};

#endif