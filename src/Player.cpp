#include "Player.h"
#include "Enemy.h"
#include "GameEngine.h"
#include <cstdlib>

Player::Player(int startX, int startY, int w, int h, int spd, const std::string& texturePath, const std::string& enemyTex, GameEngine* engine) 
    : Sprite(startX, startY, w, h, engine->loadTexture(texturePath)), speed(spd), enemyTexPath(enemyTex) {
}

void Player::update(float deltaTime, GameEngine* engine) {
    // Använder motor-Abstraktion (Key::Left)
    if (engine->isKeyDown(Key::Left) || engine->isKeyDown(Key::A)) {
        moveBy(-speed, 0); // Använder inkapslad funktion istället för x -= speed
    }
    if (engine->isKeyDown(Key::Right) || engine->isKeyDown(Key::D)) {
        moveBy(speed, 0);
    }

    if (getX() < 0) setPosition(0, getY());
    if (getX() > 750) setPosition(750, getY());

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