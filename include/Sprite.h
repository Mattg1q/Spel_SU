// ==========================================
// SPELMOTORKLASS (GENERISK DEL)
// ==========================================
#ifndef SPRITE_H
#define SPRITE_H

struct SDL_Texture;
struct SDL_Renderer;

class GameEngine;

// Vår egen Rect döljer SDL_Rect
struct Rect {
    int x, y, w, h;
};

class Sprite {
private: // Strikt inkapsling!
    bool alive;
    int x, y;
    int width, height;
    SDL_Texture* texture;

protected:
    // API för att spelklasserna (Player/Enemy) ska kunna röra sig
    void moveBy(int dx, int dy) { x += dx; y += dy; }
    void setPosition(int nx, int ny) { x = nx; y = ny; }
    int getX() const { return x; }
    int getY() const { return y; }

public:
    Sprite(int startX, int startY, int w, int h, SDL_Texture* tex);
    virtual ~Sprite();

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;

    virtual void update(float deltaTime, GameEngine* engine) = 0;
    
    // Mushantering via händelse-vidarebefordran
    virtual void onMouseDown(int mouseX, int mouseY, int button) {} 
    
    void render(SDL_Renderer* renderer);
    Rect getRect() const; // Returnerar vår egen Rect

    bool isAlive() const { return alive; }
    void setAlive(bool state) { alive = state; }
};

#endif