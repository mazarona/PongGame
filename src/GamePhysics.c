#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

void applyGeneralPhysics(Square *square, float elapsed){
    square->yForce += square-> mass * 9.8;
    square->ySpeed += square->yForce / square-> mass * elapsed;
    square->y += square->ySpeed * elapsed;
}
