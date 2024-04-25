#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
using namespace sf;
using namespace std;

class TextureManager
{
private:
    /* Conjunto das texturas usadas */
    map<string, Texture> textures;

public:
    /* Adicionar uma textura apartir de um arquivo */
    void loadTexture(const string &name, const string &filename);

    /* Transforma um id em uma referência  */
    Texture &getRef(const string &texture);

    /* Construtor */
    TextureManager()
    {
    }
};

#endif