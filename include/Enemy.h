#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include <SDL2/SDL.h>

class Enemy : public Sprite {
private:
    int x, y;
    int width, height;
    int speedY;
    SDL_Texture* texture;

public:
    Enemy(int startX, GameEngine* engine);
    virtual ~Enemy();

    void update(float deltaTime, GameEngine* engine) override;
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const override;
};

#endif