#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"
#include "../include/GamePhysics.h"

extern List rectangles;
extern SDL_Renderer *rendererGlobal;
void update(float elapsed)
{
    // Iterate over all the squares inside the linked list and call their update function set by the user
    for(List_elmt *temp = rectangles.head; temp != NULL; ){
        Rectangle *rectangle = ((Rectangle *)temp->data);
        applyPhysics(rectangle, elapsed);
        if(rectangle-> update != NULL)
            rectangle->update(rectangle, elapsed);
        temp = temp->next;
    }
}
void draw(void)
{
    SDL_SetRenderDrawColor(rendererGlobal, 0, 0, 0, 255);
    SDL_RenderClear(rendererGlobal);
    for(List_elmt *temp = rectangles.head; temp != NULL; ){
        Rectangle*rectangle = ((Rectangle *)temp->data);
        // The x and y members inside the rectangle struct are the center of the rect
        SDL_Rect rect ={
            .x = rectangle->x - (rectangle->width)/2,
            .y = rectangle->y - (rectangle->height)/2,
            .w = rectangle->width * rectangle->widthScale,
            .h = rectangle->height * rectangle->heightScale,
        };
        SDL_SetRenderDrawColor(rendererGlobal, rectangle->red, rectangle->green, rectangle->blue, rectangle->alpha);
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
