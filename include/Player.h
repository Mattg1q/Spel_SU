// ==========================================
// SPELKLASS (TILLÄMPNINGSPROGRAMMET)
// Får INTE inkludera SDL-headers
// ==========================================
#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <string>

class Player : public Sprite {
private:
    int speed;
    std::string enemyTexPath;

public:
    Player(int startX, int startY, int w, int h, int spd, const std::string& texturePath, const std::string& enemyTex, GameEngine* engine);
    virtual ~Player() {}

    void update(float deltaTime, GameEngine* engine) override;
};

#endif