#include <SDL2/SDL.h>
#define WIDTH 640
#define HEIGHT 640

int main(int argc, const char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    /* Issue draw command */
    SDL_RenderClear(renderer);
    /* Swap the background buffer with the front one */
    SDL_RenderPresent(renderer);

    SDL_Event event;
    while(SDL_WaitEvent(&event))
    {
        if(event.type == SDL_QUIT){
            break;
        }


    }
    SDL_Quit();
}
