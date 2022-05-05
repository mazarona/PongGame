#include <SDL2/SDL.h>
#include "../include/Init.h"
#include "../include/GameObjects.h"
#include "../include/GameLoop.h"

int main(int argc, const char *argv[]) {
    /***** Initialization (window and renderer) ******/
    SDL_Window *window;
    SDL_Renderer *renderer;
    const unsigned windowWidth= 640;
    const unsigned windowHeight= 480;
    const char *title= "Pong";
    Uint32 windowFlags= SDL_WINDOW_SHOWN;
    Uint32 rendererFlags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    if(!init(&window, title, windowWidth, windowHeight, windowFlags, &renderer, rendererFlags)){
        exit(1);
    }

    /***** Create game objects *****/
    int player1ID=0;
    int player2ID=1;
    int ballID=2;

    //create players
    createRectangle(player1ID, windowWidth * 0.1, windowHeight/2, 5, windowHeight * 0.1, 1, 0, 0, 0, 0, 255, 0, 0, 255, false, NULL);
    createRectangle(player2ID, windowWidth * 0.9, windowHeight/2, 5, windowHeight * 0.1, 1, 0, 0, 0, 0, 255, 0, 0, 255, false, NULL);
    //create ball
    const float ballSize = 10;
    const float ballSpeedX = 200;
    const float ballSpeedY = 200;
    createRectangle(ballID, windowWidth/ 2, windowHeight/2, ballSize, ballSize, 1, ballSpeedX, ballSpeedY, 0, 0, 255, 0, 0, 255, false, NULL);

    /***** Start the Game *****/
    startGame();
    return 0;
}
