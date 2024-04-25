#include "headers/game.h"
#include "headers/game_state.h"

void Game::loadTextures()
{
    texmgr.loadTexture("background", "./assets/background.png");
}

void Game::pushState(GameState *state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState *state)
{
    if (!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState *Game::peekState()
{
    if (this->states.empty())
        return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    Clock clock;

    while (this->window.isOpen())
    {
        Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (peekState() == nullptr)
            continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->loadTextures();

    this->window.create(VideoMode(800, 600), "Pixelopolis");
    this->window.setFramerateLimit(60);
    
    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while (!this->states.empty())
        popState();
}
