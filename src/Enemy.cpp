#include "Enemy.h"
#include "GameEngine.h"

// Initiera med värden från spelet (main), skickar de grafiska till Sprite
Enemy::Enemy(int startX, int startY, int w, int h, int spdY, const std::string& texturePath, GameEngine* engine)
    : Sprite(startX, startY, w, h, engine->loadTexture(texturePath)), speedY(spdY) {
}

void Enemy::update(float deltaTime, GameEngine* engine) {
    moveBy(0, speedY); // Inkapslad metod för rörelse

    if (getY() > 600) { // Inkapslad metod för position
        engine->quit();
    }
}