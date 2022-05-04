#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

void applyPhysics(Rectangle *rectangle, float elapsed){
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
        //rectangle->ySpeed = -abs((int)rectangle->ySpeed);
        rectangle->ySpeed =0;
    }
    rectangle->xSpeed += rectangle->xForce / rectangle-> mass * elapsed;
    rectangle->x += rectangle->xSpeed * elapsed;
    if((rectangle->y) < (480 - rectangle->height/2))
        rectangle->ySpeed += rectangle->yForce / rectangle-> mass * elapsed;
    rectangle->y += rectangle->ySpeed * elapsed;
}
