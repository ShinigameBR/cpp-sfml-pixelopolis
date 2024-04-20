#include "game.h"
#include "game_state.h"

void Game::pushState(GameState* state)
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

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);
 
    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    Clock clock;
 
    while(this->window.isOpen())
    {
        Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
 
        if(peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}
 
Game::Game()
{
    this->window.create(VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);
}
 
Game::~Game()
{
    while(!this->states.empty()) popState();    
}
