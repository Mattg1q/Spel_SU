#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <SDL2/SDL.h>

class Player : public Sprite {
private:
    int x, y;
    int width, height;
    int speed;
    SDL_Texture* texture;

public:
    Player(int startX, int startY, GameEngine* engine);
    virtual ~Player();

    void update(float deltaTime, GameEngine* engine) override;
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const override;
};

#endif