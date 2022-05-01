#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

extern List squares;
extern SDL_Renderer *rendererGlobal;
void update(float elapsed)
{
    // Iterate over all the squares inside the linked list and call their update function set by the user
    for(List_elmt *temp = squares.head; temp != NULL; ){
        Square *square = ((Square *)temp->data);
        square->update(square, elapsed);
        temp = temp->next;
    }
}
void draw(void)
{
    SDL_SetRenderDrawColor(rendererGlobal, 0, 0, 0, 255);
    SDL_RenderClear(rendererGlobal);
    for(List_elmt *temp = squares.head; temp != NULL; ){
        Square *square = ((Square *)temp->data);
        SDL_Rect rect ={
            .x = square->x - (square->size)/2,
            .y = square->y - (square->size)/2,
            .w = square->size,
            .h = square->size,
        };
        SDL_SetRenderDrawColor(rendererGlobal, square->red, square->green, square->blue, square->alpha);
        SDL_RenderFillRect(rendererGlobal, &rect);
        temp = temp->next;
    }
    SDL_RenderPresent(rendererGlobal);
}
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
        update(elapsed);
        draw();
        lastTick = currentTick;
    }

}
