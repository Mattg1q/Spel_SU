#define SDL_MAIN_HANDLED
#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "Constants.h"

int main(int argc, char* argv[]) {
    GameEngine engine;
    
    if (!engine.init()) {
        return 1;
    }
    
    // Konfigurera spelet från main. (startX, startY, width, height, speed, playerTexture, enemyTexture, engine)
    engine.addSprite(new Player(400, 550, 50, 50, 5, gPlayerPng, gEnemyPng, &engine));
    
    // Lärarens feedback punkt 1: Minst två Enemy-objekt med olika position och fart. (startX, startY, width, height, speedY, texture, engine)
    engine.addSprite(new Enemy(100, -20, 40, 40, 2, gEnemyPng, &engine));
    engine.addSprite(new Enemy(400, -150, 40, 40, 3, gEnemyPng, &engine));
    engine.addSprite(new Enemy(650, -80, 40, 40, 1, gEnemyPng, &engine));
    
    engine.run();
    
    return 0;
}