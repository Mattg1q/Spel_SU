// ==========================================
// SPELMOTORKLASS (GENERISK DEL)
// ==========================================
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>

// Forward declarations för att dölja SDL från spelklasserna
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class Sprite;

// Vår egen Key-enum för att helt dölja SDL_Scancode
enum class Key {
    Left, Right, Up, Down, A, D, W, S, Space
};

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

    void quit() { running = false; }
    bool init();
    void addSprite(Sprite* sprite);
    void run();
    void cleanup();

    // Endast det säkra API:et exponeras
    bool checkCollision(Sprite* a, Sprite* b); 
    
    // Använder vår egen Key istället för SDL_Scancode
    bool isKeyDown(Key key) const; 
    
    SDL_Texture* loadTexture(const std::string& path);
    SDL_Renderer* getRenderer() const { return renderer; }
    const std::vector<Sprite*>& getSprites() const { return sprites; }
};

#endif