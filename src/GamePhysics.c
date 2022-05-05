#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"
#include "../include/globals.h"

void applyPhysics(Rectangle *rectangle, float elapsed){
    // Iterate over all of the objects then find the ball then find the collision
    for(List_elmt *temp = rectangles.head; temp != NULL; ){
        Rectangle *rectangle2 = ((Rectangle *)temp->data);
        if(rectangle != rectangle2 && rectangle2->width == rectangle2->height){
            if(SDL_HasIntersection(&(rectangle->rect), &(rectangle2->rect)) == SDL_TRUE){
                rectangle2->xSpeed = -rectangle2->xSpeed;
            }
        }
        temp = temp->next;
    }
    if((rectangle->x) < (rectangle->width/2)){
        rectangle->xSpeed = abs((int)rectangle->xSpeed);
    }
    if((rectangle->x) > (640 - rectangle->width/2)){
        rectangle->xSpeed = -abs((int)rectangle->xSpeed);
    }
    if((rectangle->y) < (rectangle->height/2)){
        rectangle->ySpeed = abs((int)rectangle->ySpeed);
    }
    if((rectangle->y) > (480 - rectangle->height/2)){
        rectangle->ySpeed = -abs((int)rectangle->ySpeed);
    }
    // Dynamics (Newton laws)
    rectangle->xSpeed += rectangle->xForce / rectangle-> mass * elapsed;
    rectangle->x += rectangle->xSpeed * elapsed;
    rectangle->ySpeed += rectangle->yForce / rectangle-> mass * elapsed;
    rectangle->y += rectangle->ySpeed * elapsed;
    rectangle->rect.x = rectangle->x - (rectangle->width)/2;
    rectangle->rect.y = rectangle->y - (rectangle->height)/2;
}

void update(float elapsed)
{
    // Iterate over all the rectangles inside the linked list.
    for(List_elmt *temp = rectangles.head; temp != NULL; ){
        Rectangle *rectangle = ((Rectangle *)temp->data);
        applyPhysics(rectangle, elapsed);
        // call the user defined call back update function if not NULL.
        if(rectangle-> update != NULL)
            rectangle->update(rectangle, elapsed);
        temp = temp->next;
    }
}
