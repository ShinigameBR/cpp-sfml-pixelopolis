#include "headers/game_state_editor.h"

void GameStateEditor::draw(const float dt)
{
    this->game->window.clear(Color::Black);
    this->game->window.draw(this->game->background);

    return;
}

void GameStateEditor::update(const float dt)
{
    return;
}

void GameStateEditor::handleInput()
{
    Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
        /* Close the window */
        case Event::Closed:
        {
            this->game->window.close();
            break;
        }
        /* Resize the window */
        case Event::Resized:
        {
            gameView.setSize(event.size.width, event.size.height);
            guiView.setSize(event.size.width, event.size.height);
            this->game->background.setPosition(this->game->window.mapPixelToCoords(Vector2i(0, 0), this->guiView));
            this->game->background.setScale(
                float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
            break;
        }
        default:
            break;
        }
    }

    return;
}

GameStateEditor::GameStateEditor(Game *game)
{
    this->game = game;
    Vector2f pos = Vector2f(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);
}