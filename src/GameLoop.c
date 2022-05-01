#include <stdbool.h>
#include <SDL2/SDL.h>

void startGame(void)
{
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

}
