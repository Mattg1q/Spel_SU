#include "Sprite.h"

Sprite::Sprite(int startX, int startY, int w, int h, SDL_Texture* tex)
    : alive(true), x(startX), y(startY), width(w), height(h), texture(tex) {
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::render(SDL_Renderer* renderer) {
    SDL_Rect rect = getRect();
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

SDL_Rect Sprite::getRect() const {
    return {x, y, width, height};
}