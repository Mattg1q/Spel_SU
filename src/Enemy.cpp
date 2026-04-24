#include "Enemy.h"
#include "GameEngine.h"
#include <cstdlib>

// Initiera med värden från spelet (main), skickar de grafiska till Sprite
Enemy::Enemy(int startX, int startY, int w, int h, int spdY, const std::string& texturePath, GameEngine* engine)
    : Sprite(startX, startY, w, h, engine->loadTexture(texturePath)), speedY(spdY) {
}

void Enemy::update(float deltaTime, GameEngine* engine) {
    y += speedY;

    if (y > 600) {
        // Lärarens feedback punkt 2: Spelet skall avslutas när en fiende når botten
        engine->quit();
    }
}