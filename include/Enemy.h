#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <string> // Lägg till string

class Enemy : public Sprite {
private:
    int x, y;
    int width, height;
    int speedY;
    SDL_Texture* texture;

public:
    // Konstruktorn tar nu emot storlek, hastighet och textur
    Enemy(int startX, int startY, int w, int h, int spdY, const std::string& texturePath, GameEngine* engine);
    virtual ~Enemy();

    void update(float deltaTime, GameEngine* engine) override;
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const override;
};

#endif