#include "headers/game_state_start.h"

void GameStateStart::loadgame()
{
    this->game->pushState(new GameStateEditor(this->game));

    return;
}

void GameStateStart::draw(const float dt)
{
    this->game->window.setView(this->view);

    this->game->window.clear(Color::Black);
    this->game->window.draw(this->game->background);

    return;
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput()
{
    Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
        /* Fechar a aplicação */
        case Event::Closed:
        {
            game->window.close();
            break;
        }

        /* Redimensionar a aplicação */
        case Event::Resized:
        {
            this->view.setSize(event.size.width, event.size.height);
            this->game->background.setPosition(this->game->window.mapPixelToCoords(Vector2i(0, 0)));
            this->game->background.setScale(
                float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
            break;
        }
        case Event::KeyPressed:
        {
            if (event.key.code == sf::Keyboard::Escape)
                this->game->window.close();
            else if (event.key.code == sf::Keyboard::Space)
                this->loadgame();
            break;
        }
        default:
            break;
        }
    }

    return;
}

GameStateStart::GameStateStart(Game *game)
{
    this->game = game;
    Vector2f pos = Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}
