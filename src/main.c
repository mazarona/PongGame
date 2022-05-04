#include <SDL2/SDL.h>
#include "../include/Init.h"
#include "../include/GameObjects.h"
#include "../include/GameLoop.h"

//void createRandSquares(unsigned n);

const unsigned windowWidth= 640;
const unsigned windowHeight= 480;
//void updateSquare(Square *sq, float elapsed);
int main(int argc, const char *argv[]) {
    /***** Initialization (window and renderer) ******/
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char *title= "Pong";
    Uint32 windowFlags= SDL_WINDOW_SHOWN;
    Uint32 rendererFlags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    if(!init(&window, title, windowWidth, windowHeight, windowFlags, &renderer, rendererFlags)){
        exit(1);
    }

    /***** Create game objects *****/

    createSquare(200, 100, 40, 0, 200, 5, 2000, 20000, 255, 0, 0, 255, true, NULL);
    int thick = 5;
    createLine(0, 0, windowWidth, windowHeight,thick, 0, 0, 1,0,0, 255, 0, 0, 255, true, NULL);
    //createRandSquares(10);

    /***** Start the Game *****/
    startGame();
    return 0;
}

//void updateSquare(Square *sq, float elapsed){
//    sq->x += sq->xSpeed * elapsed;
//    if((sq->x) < (sq->size/2)){
//        sq->xSpeed = abs((int)sq->xSpeed);
//    }
//    if((sq->x) > (windowWidth - sq->size/2)){
//        sq->xSpeed = -abs((int)sq->xSpeed);
//    }
//    if((sq->y) < (sq->size/2)){
//        sq->ySpeed = abs((int)sq->ySpeed);
//    }
//    if((sq->y) > (windowHeight - sq->size/2)){
//        sq->ySpeed = -abs((int)sq->ySpeed);
//    }
//}

//void createRandSquares(unsigned n)
//{
//    for(unsigned i = 0; i < n; i++){
//        createSquare(rand()%400, rand()%400,rand()%100 + 1,rand()%100,
//                rand()%100, rand()%10 + 1, rand()%256, rand()%256, rand()%256,
//                rand()%256,true,NULL);
//    }
//
//}
