#include "Enemy.h"
#include "GameEngine.h"
#include <cstdlib>

// Initiera med värden från spelet (main)
Enemy::Enemy(int startX, int startY, int w, int h, int spdY, const std::string& texturePath, GameEngine* engine)
    : x(startX), y(startY), width(w), height(h), speedY(spdY) {
    texture = engine->loadTexture(texturePath);
}

Enemy::~Enemy() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Enemy::update(float deltaTime, GameEngine* engine) {
    y += speedY;

    if (y > 600) {
        // Lärarens feedback punkt 2: Spelet skall avslutas när en fiende når botten
        engine->quit();
    }
}

void Enemy::render(SDL_Renderer* renderer) {
    SDL_Rect rect = getRect();
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

SDL_Rect Enemy::getRect() const {
    return {x, y, width, height};
}