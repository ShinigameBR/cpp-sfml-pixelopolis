#ifndef ANIMATION_HANDLER_H
#define ANIMATION_HANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Animation
{
public:
    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration)
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }

    unsigned int getLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler
{
private:
    /* Conjunto de animações */
    vector<Animation> animations;

    /* Tempo atual desde o início do loop de animação */
    float t;

    int currentAnim;

public:
    /* Adicionar uma nova animação */
    void addAnim(Animation &anim);

    /* Atualiza o quadro atual da animação. dt é o tempo desde
     * que a última atualização foi chamada (ou seja, o tempo
     * para um quadro ser executado) */
    void update(const float dt);

    /* Trocar a animação. Reseta t como parte do processo. */
    void changeAnim(unsigned int animNum);

    /* Atual parte da textura que deve ser mostrada. */
    IntRect bounds;

    /* Dimensões em pixel para cada frame individual */
    IntRect frameSize;

    /* Construtor */
    AnimationHandler()
    {
        this->t = 0.0f;
        this->currentAnim = -1;
    }

    AnimationHandler(const IntRect &frameSize)
    {
        this->frameSize = frameSize;

        this->t = 0.0f;
        this->currentAnim = -1;
    }
};

#endif