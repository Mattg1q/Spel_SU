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
    
    engine.addSprite(new Player(400, 550, &engine));
    engine.addSprite(new Enemy(400, &engine));
    
    engine.run();
    
    return 0;
}