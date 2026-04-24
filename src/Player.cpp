#include "Player.h"
#include "Enemy.h"
#include "GameEngine.h"
#include <cstdlib>

Player::Player(int startX, int startY, int w, int h, int spd, const std::string& texturePath, const std::string& enemyTex, GameEngine* engine) 
    : Sprite(startX, startY, w, h, engine->loadTexture(texturePath)), speed(spd), enemyTexPath(enemyTex) {
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
        
        // Nu använder vi den nya kollisionsfunktionen som tar Sprite-pekare
        if (enemy && enemy->isAlive() && engine->checkCollision(this, enemy)) {
            enemy->setAlive(false);
            
            int randomSpeed = 1 + (rand() % 4); 
            engine->addSprite(new Enemy(rand() % 760, -50, 40, 40, randomSpeed, enemyTexPath, engine)); 
        }
    }
}