#include "Player.h"
#include "Enemy.h"
#include "GameEngine.h"
#include "Constants.h"
#include <cstdlib>

Player::Player(int startX, int startY, GameEngine* engine) 
    : x(startX), y(startY), width(50), height(50), speed(5) {
    texture = engine->loadTexture(gPlayerPng);
}

Player::~Player() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Player::update(float deltaTime, GameEngine* engine) {
    if (engine->isKeyDown(SDL_SCANCODE_LEFT) || engine->isKeyDown(SDL_SCANCODE_A)) {
        x -= speed;
    }
    if (engine->isKeyDown(SDL_SCANCODE_RIGHT) || engine->isKeyDown(SDL_SCANCODE_D)) {
        x += speed;
    }

    if (x < 0) x = 0;
    if (x > 750) x = 750;

    const std::vector<Sprite*>& allSprites = engine->getSprites();
    for (Sprite* s : allSprites) {
        Enemy* enemy = dynamic_cast<Enemy*>(s);
        
        if (enemy && enemy->isAlive() && engine->checkCollision(getRect(), enemy->getRect())) {
            enemy->setAlive(false);
            engine->addSprite(new Enemy(rand() % 760, engine)); 
        }
    }
}

void Player::render(SDL_Renderer* renderer) {
    SDL_Rect rect = getRect();
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    } else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

SDL_Rect Player::getRect() const {
    return {x, y, width, height};
}