#include "Enemy.h"
#include "GameEngine.h"
#include "Constants.h"
#include <cstdlib>

Enemy::Enemy(int startX, GameEngine* engine)
    : x(startX), y(0), width(40), height(40), speedY(2) {
    texture = engine->loadTexture(gEnemyPng);
}

Enemy::~Enemy() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Enemy::update(float deltaTime, GameEngine* engine) {
    y += speedY;

    if (y > 600) {
        setAlive(false);
        engine->addSprite(new Enemy(rand() % 760, engine));
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