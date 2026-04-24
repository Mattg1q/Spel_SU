// ==========================================
// SPELMOTORKLASS (GENERISK DEL)
// Hanterar SDL och rendering bakom kulisserna
// ==========================================
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class GameEngine;

class Sprite {
protected:
    bool alive;
    int x, y;
    int width, height;
    SDL_Texture* texture;

public:
    Sprite(int startX, int startY, int w, int h, SDL_Texture* tex);
    virtual ~Sprite();

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;

    virtual void update(float deltaTime, GameEngine* engine) = 0;
    
    // Nu är render och getRect konkreta funktioner i motorn
    void render(SDL_Renderer* renderer);
    SDL_Rect getRect() const;

    bool isAlive() const { return alive; }
    void setAlive(bool state) { alive = state; }
};

#endif