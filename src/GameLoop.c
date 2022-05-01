#include <stdbool.h>
#include <SDL2/SDL.h>
#include "../include/linked_list.h"
#include "../include/GameObjects.h"

extern List squares;
void update(float elapsed)
{
    // Iterate over all the squares inside the linked list and call their update function set by the user
    for(List_elmt *temp = squares.head; temp != NULL; ){
        Square *square = ((Square *)temp->data);
        square->update(square, elapsed);
        temp = temp->next;
    }
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
        lastTick = SDL_GetTicks();
    }

}
