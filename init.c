#include "init.h"


static SDL_Window *windowHelper = NULL ;
static SDL_Renderer *rendererHelper = NULL ;
static void shutDown(void){
    if(rendererHelper){
        SDL_DestroyRenderer(rendererHelper);
    }
    if(windowHelper){
        SDL_DestroyWindow(windowHelper);
    }
    SDL_Quit();
}

bool init(SDL_Window **window,const char *title, int w, int h, Uint32 windowFlags, 
        SDL_Renderer **renderer, Uint32 rendererFlags){
    srand((unsigned int)time(NULL));
    // Set shutdown as a callback when exiting

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    // Create window
    *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h, windowFlags);
    if(!window){
        return false;
    }
    windowHelper = *window;

    // Create renderer
    *renderer = SDL_CreateRenderer(*window, -1, rendererFlags);
    if(!renderer){
        return false;
    }
    rendererHelper = *renderer;

    atexit(shutDown);
    return true;
}

bool coinFlip(void){return rand() % 2 == 1? true : false;}
