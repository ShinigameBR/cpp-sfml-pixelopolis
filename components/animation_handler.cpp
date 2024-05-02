#include "headers/animation_handler.h"

void AnimationHandler::update(const float dt)
{
    if(currentAnim >= this->animations.size() || currentAnim < 0) return;
 
    float duration = this->animations[currentAnim].duration;
 
    /* Verifica se a animação progrediu para um novo frame e
     * se sim muda para o próximo frame */
    if(int((t + dt) / duration) > int(t / duration))
    {
        /* Calcular o número do frame */
        int frame = int((t + dt) / duration);
 
        /* Ajustar para o loop */
        frame %= this->animations[currentAnim].getLength();
 
        /* Definir o sprite para o novo frame */
        sf::IntRect rect = this->frameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * this->currentAnim;
        this->bounds = rect;
    }
 
    /* Incrementar o tempo decorrido */
    this->t += dt;
    /* Ajustar para o loop */
    if(this->t > duration * this->animations[currentAnim].getLength())
    {
        this->t = 0.0f;
    }
 
    return;
}

void AnimationHandler::addAnim(Animation& anim)
{
    this->animations.push_back(anim);
 
    return;
}

void AnimationHandler::changeAnim(unsigned int animID)
{
    /* Não mudar a animação caso ela esteja ativa ou
     * a nova animação não existir */
    if(this->currentAnim == animID || animID >= this->animations.size() ||
        animID < 0) return;
 
    /* Definir a animação atual */
    this->currentAnim = animID;
    /* Atualizar os limites da animação */
    sf::IntRect rect = this->frameSize;
    rect.top = rect.height * animID;
    this->bounds = rect;
    this->t = 0.0;
 
    return;
}