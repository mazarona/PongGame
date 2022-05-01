#include "init.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct Ball {
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    int size;
}Ball;
Ball makeBall (int size);

SDL_Window *window;
SDL_Renderer *renderer;
int main(int argc, const char *argv[]) {
    /* Initialization */
    char *title= "Pong";
    int windowWidth= WINDOW_WIDTH;
    int windowHeight= WINDOW_HEIGHT;
    Uint32 windowFlags= SDL_WINDOW_SHOWN;
    Uint32 rendererFlags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    if(!init(&window, title, windowWidth, windowHeight, windowFlags, &renderer, rendererFlags)){
        exit(1);
    }
    /* Create game objects */

    /* Event loop */
    SDL_Event event;
    bool quit = false;
    Uint32 lastTick = SDL_GetTicks();
    Uint32 currentTick = 0;
    Uint32 diff = 0;
    float elapsed = 0;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
        currentTick = SDL_GetTicks();
        diff = currentTick - lastTick;
        elapsed = diff / 1000.0f;
        lastTick = SDL_GetTicks();
    }
    return 0;
}

void update(float elapsed){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    /* Swap the background buffer with the front one */
    SDL_RenderPresent(renderer);
}

Ball makeBall(int size)
{
    const float speed = 120;
    Ball ball = {
        .x = WINDOW_WIDTH/2 - size/2,
        .y = WINDOW_HEIGHT/2 - size/2,
        .size = 10,
    };
}
