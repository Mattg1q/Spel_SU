#include "Sprite.h"
#include <SDL2/SDL.h> // SDL existerar bara här!

Sprite::Sprite(int startX, int startY, int w, int h, SDL_Texture* tex)
    : alive(true), x(startX), y(startY), width(w), height(h), texture(tex) {
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::render(SDL_Renderer* renderer) {
    Rect r = getRect();
    SDL_Rect sdl_rect = {r.x, r.y, r.w, r.h}; // Konvertera egen Rect till SDL_Rect
    
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &sdl_rect);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &sdl_rect);
    }
}

Rect Sprite::getRect() const {
    return {x, y, width, height};
}