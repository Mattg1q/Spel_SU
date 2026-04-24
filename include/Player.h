#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <string> // Lägg till string

class Player : public Sprite {
private:
    int x, y;
    int width, height;
    int speed;
    SDL_Texture* texture;
    std::string enemyTexPath; // Spara sökvägen till fiendens textur så vi kan spawna nya

public:
    // Konstruktorn tar nu emot parametrar
    Player(int startX, int startY, int w, int h, int spd, const std::string& texturePath, const std::string& enemyTex, GameEngine* engine);
    virtual ~Player();

    void update(float deltaTime, GameEngine* engine) override;
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const override;
};

#endif