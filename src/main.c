#include <SDL2/SDL.h>
#include "../include/Init.h"
#include "../include/GameObjects.h"
#include "../include/GameLoop.h"


void updateSquare(Square *sq, float elapsed);
int main(int argc, const char *argv[]) {
    /***** Initialization (window and renderer) ******/
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

    /***** Create game objects *****/
    createSquare(windowWidth/2, windowHeight/2, 10, 100.0, 100.0, 255,0,0,255,updateSquare);
    createSquare(windowWidth/3, windowHeight/3, 30, 50, 50, 0,255,0,255,updateSquare);

    /***** Start the Game *****/
    startGame();
    return 0;
}

void updateSquare(Square *sq, float elapsed){
    sq->x += sq->xSpeed * elapsed;
    sq->y += sq->ySpeed * elapsed;
}
