#include <SDL2/SDL.h>
#include "../include/GamePhysics.h"
#include "../include/Draw.h"
#include "../include/globals.h"

void handleKeyPressed(SDL_Keysym *key);
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
            switch(event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    handleKeyPressed(&event.key.keysym);
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

void handleKeyPressed(SDL_Keysym *key)
{
    switch(key->sym)
    {
        case SDLK_UP:
            for(List_elmt *temp = rectangles.head; temp != NULL; ){
                Rectangle *rectangle = ((Rectangle *)temp->data);
                if(rectangle->id == 0)
                {
                    rectangle->ySpeed = -200;
                    printf("y: %f\n", rectangle->y);
                }
                temp = temp->next;
            }
            break;
        case SDLK_DOWN:
            for(List_elmt *temp = rectangles.head; temp != NULL; ){
                Rectangle *rectangle = ((Rectangle *)temp->data);
                if(rectangle->id == 0)
                    rectangle->ySpeed = 200;
                temp = temp->next;
            }
            printf("key down pressed\n");
            break;
        case SDLK_KP_2:
            for(List_elmt *temp = rectangles.head; temp != NULL; ){
                Rectangle *rectangle = ((Rectangle *)temp->data);
                if(rectangle->id == 1)
                {
                    rectangle->y +=10;
                    printf("y: %f\n", rectangle->y);
                }
                temp = temp->next;
            }
            break;
        case SDLK_KP_8:
            for(List_elmt *temp = rectangles.head; temp != NULL; ){
                Rectangle *rectangle = ((Rectangle *)temp->data);
                if(rectangle->id == 1)
                {
                    rectangle->y -=10;
                    printf("y: %f\n", rectangle->y);
                }
                temp = temp->next;
            }
            break;
    }

}
