#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class GameEngine;

class Sprite {
protected:
    bool alive;

public:
    Sprite() : alive(true) {}
    virtual ~Sprite() {}

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;

    virtual void update(float deltaTime, GameEngine* engine) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual SDL_Rect getRect() const = 0;

    bool isAlive() const { return alive; }
    void setAlive(bool state) { alive = state; }
};

#endif