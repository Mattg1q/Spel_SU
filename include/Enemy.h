// ==========================================
// SPELKLASS (TILLÄMPNINGSPROGRAMMET)
// Får INTE inkludera SDL-headers
// ==========================================
#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include <string>

class Enemy : public Sprite {
private:
    int speedY;

public:
    Enemy(int startX, int startY, int w, int h, int spdY, const std::string& texturePath, GameEngine* engine);
    virtual ~Enemy() {}

    void update(float deltaTime, GameEngine* engine) override;
};

#endif