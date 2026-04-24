#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

class Sprite;

class GameEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    std::vector<Sprite*> sprites;
    std::vector<Sprite*> addedSprites;

public:
    GameEngine();
    ~GameEngine();

    // Lägg till denna funktion:
    void quit() { running = false; }
    
    bool init();
    void addSprite(Sprite* sprite);
    void run();
    void cleanup();

    bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
    SDL_Renderer* getRenderer() const;
    const std::vector<Sprite*>& getSprites() const;
    
    bool isKeyDown(SDL_Scancode key) const; 
    SDL_Texture* loadTexture(const std::string& path);
};

#endif