#include <SDL2/SDL.h>
#include "../include/Init.h"
#include "../include/GameObjects.h"
#include "../include/GameLoop.h"

Rectangle *ballGlobal;
Rectangle *player1Global;
Rectangle *player2Global;
void updateState(Rectangle *rectangle, float elapsed);
int main(int argc, const char *argv[]) {
    /***** Initialization (window and renderer) ******/
    SDL_Window *window;
    SDL_Renderer *renderer;
    const unsigned windowWidth= 680;
    const unsigned windowHeight= 420;
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
    const float player1PositionX = windowWidth * 0.1;
    const float player2PositionX = windowWidth * 0.9;
    const float playerPositionY = windowHeight * 0.5;
    const float playerWidth = windowWidth * 0.008;
    const float playerHeight = windowHeight * 0.1;
    
    Rectangle *player1 = createRectangle(player1ID, player1PositionX, playerPositionY, playerWidth, playerHeight, 1, 0, 0, 0, 0, 255, 0, 0, 255, false, updateState);
    player1Global = player1;
    Rectangle *player2 = createRectangle(player2ID, player2PositionX, playerPositionY, playerWidth, playerHeight, 1, 0, 0, 0, 0, 0, 0, 255, 255, false, updateState);
    player2Global = player2;

    //create ball
    const float ballPositionX = windowWidth/2.0;
    const float ballPositionY = windowHeight/2.0;
    const float ballSize = windowWidth/100.0;
    const float ballSpeedX = windowWidth/2.5;
    const float ballSpeedY = windowWidth/3.0;
    Rectangle *ball = createRectangle(ballID, ballPositionX, ballPositionY, ballSize, ballSize, 1, ballSpeedX, ballSpeedY, 0, 0, 255, 255, 255, 255, false, updateState);
    ballGlobal = ball;

    /***** Start the Game *****/
    startGame();
    return 0;
}

void updateState(Rectangle *rectangle, float elapsed){
    int speedIncreaseRate = 3;
    if(SDL_HasIntersection(&(player1Global->rect), &(ballGlobal->rect)) == SDL_TRUE){
        ballGlobal->xSpeed = - ballGlobal->xSpeed;
        ballGlobal->xSpeed += (ballGlobal->xSpeed > 0)? speedIncreaseRate: -speedIncreaseRate;
    }
    if(SDL_HasIntersection(&(player2Global->rect), &(ballGlobal->rect)) == SDL_TRUE){
        ballGlobal->xSpeed = - ballGlobal->xSpeed;
        ballGlobal->xSpeed += (ballGlobal->xSpeed > 0)? speedIncreaseRate: -speedIncreaseRate;
    }
}
