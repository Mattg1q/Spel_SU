#include "GameEngine.h"
#include "Sprite.h"
#include <cstdlib>
#include <ctime>

GameEngine::GameEngine() : window(nullptr), renderer(nullptr), running(false) {
    srand(time(0));
}

GameEngine::~GameEngine() {
    cleanup();
}

bool GameEngine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        return false;
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        return false;
    }

    running = true;
    return true;
}

void GameEngine::addSprite(Sprite* sprite) {
    addedSprites.push_back(sprite);
}

const std::vector<Sprite*>& GameEngine::getSprites() const {
    return sprites;
}

void GameEngine::run() {
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        for (Sprite* s : addedSprites) {
            sprites.push_back(s);
        }
        addedSprites.clear();

        for (Sprite* s : sprites) {
            s->update(0.016f, this);
        }

        for (auto it = sprites.begin(); it != sprites.end(); ) {
            if (!(*it)->isAlive()) {
                delete *it;
                it = sprites.erase(it);
            } else {
                ++it;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (Sprite* s : sprites) {
            s->render(renderer);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }
}

void GameEngine::cleanup() {
    for (Sprite* sprite : sprites) {
        delete sprite;
    }
    sprites.clear();

    for (Sprite* sprite : addedSprites) {
        delete sprite;
    }
    addedSprites.clear();

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    IMG_Quit();
    SDL_Quit();
}

bool GameEngine::checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    return SDL_HasIntersection(&a, &b);
}

SDL_Renderer* GameEngine::getRenderer() const {
    return renderer;
}

bool GameEngine::isKeyDown(SDL_Scancode key) const {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    return keystate[key];
}

SDL_Texture* GameEngine::loadTexture(const std::string& path) {
    return IMG_LoadTexture(renderer, path.c_str());
}