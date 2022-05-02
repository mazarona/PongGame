#include <stdlib.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

/* Keep track of created game objects in a linked list*/
List squares;
static void destroySquares(void *data){free((Square *) data);}

void createSquare(float x, float y, int size, float xSpeed, float ySpeed, float mass,
        int red, int green, int blue, int alpha, bool physics ,void(*update)(struct Square*, float elapsed))
{
    // Initialize the linked list only once
    static bool initialize = false;
    if(!initialize){
        list_init(&squares, destroySquares);
        initialize = true;
    }

    // Create the square and add to the linked list
    // the square will be freed in two cases
    //  1) shutDown function will destroy all of the linked list
    //  2) when removing an element from the linked list it will free it using the
    //      provided destry function above
    Square *sq = (Square *)malloc(sizeof(Square));
    sq->x = x;
    sq->y = y;
    sq->size = size;
    sq->mass = mass;
    sq->xForce = 0;
    sq->yForce = 0;
    sq->xSpeed = xSpeed;
    sq->ySpeed = ySpeed;
    sq->red = red;
    sq->green = green;
    sq->blue = blue;
    sq->alpha = alpha;
    sq->physics = physics;
    sq->update = update;
    list_ins_next(&squares, NULL, sq);
}

