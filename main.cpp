#include "cleanup.h"
#include "drawing_functions.h"
#include "res_path.h"
#include <SDL2/SDL_mixer.h>

int main(int argc, char **argv) {
    // setup SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    // setup window
    SDL_Window *window = SDL_CreateWindow("Cyborg Battle",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 352,
                                          SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // setup renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        cleanup(window);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_RenderSetLogicalSize(renderer, 640, 352);

    // init SDL image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        return 1;
    }

    // initialize text to font
    if (TTF_Init() != 0) {
        SDL_Quit();
        cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
        return 1;
    }

    // init SDL mixer
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        SDL_Quit();
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        return 1;
    }

    // load up texture to draw
    string resPath = getResourcePath();
    SDL_Texture *texture = loadTexture(resPath + "map.png", renderer);

    // run game for 5000 ticks (5000ms)
    while (SDL_GetTicks() < 5000) {
        // clear the screen
        SDL_RenderClear(renderer);

        // draw what we want to draw
        renderTexture(texture, renderer, 0, 0);

        // show image we've been rendering
        SDL_RenderPresent(renderer);
    }

    cleanup(renderer);
    cleanup(window);
    cleanup(texture);

    SDL_Quit();
    return 0;
}