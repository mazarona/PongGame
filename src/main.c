#include <SDL2/SDL.h>
#include "../include/init.h"
#include "../include/GameObjects.h"
#include "../include/GameLoop.h"


int main(int argc, const char *argv[]) {
    /* Initialization (window and renderer) */
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char *title= "Pong";
    const unsigned windowWidth= 640;
    const unsigned windowHeight= 480;
    Uint32 windowFlags= SDL_WINDOW_SHOWN;
    Uint32 rendererFlags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    if(!init(&window, title, windowWidth, windowHeight, windowFlags, &renderer, rendererFlags)){
        exit(1);
    }
    /* Create game objects */
    createSquare

    /* Start the Game */
    startGame();
    return 0;
}

void updateSquare(Square *sq, float ela)
{

}


//void update(float elapsed){
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer);
//
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    /* Swap the background buffer with the front one */
//    SDL_RenderPresent(renderer);
//}
//
//Ball makeBall(int size)
//{
//    const float speed = 120;
//    Ball ball = {
//        .x = WINDOW_WIDTH/2 - size/2,
//        .y = WINDOW_HEIGHT/2 - size/2,
//        .size = 10,
//    };
//}
