#include "headers/texture_manager.h"

void TextureManager::loadTexture(const string &name, const string &filename)
{
    /* Carregar a textura */
    Texture tex;
    tex.loadFromFile(filename);

    /* Adicionar a lista de texturas */
    this->textures[name] = tex;

    return;
}

Texture &TextureManager::getRef(const string &texture)
{
    return this->textures.at(texture);
}