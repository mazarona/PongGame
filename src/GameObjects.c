#include <stdlib.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

/* Keep track of created game objects in a linked list*/
List rectangles;

static void destroyRectangles(void *data){free((Rectangle *) data);}
void createSquare(float x, float y, int size, float xSpeed, float ySpeed, float mass, float xForce, float yForce,
        int red, int green, int blue, int alpha, bool physics ,void(*update)(struct Rectangle*, float elapsed))
{
    // Initialize the linked list only once
    static bool initialize = false;
    if(!initialize){
        list_init(&rectangles, destroyRectangles);
        initialize = true;
    }

    // Create the square and add to the linked list
    // the square will be freed in two cases
    //  1) shutDown function will destroy all of the linked list
    //  2) when removing an element from the linked list it will free it using the
    //      provided destry function above
    Rectangle *sq = (Rectangle *)malloc(sizeof(Rectangle));
    sq->x = x;
    sq->y = y;
    sq->width = size;
    sq->height = size;
    sq->mass = mass;
    sq->widthScale = 1;
    sq->heightScale = 1;
    sq->xForce = xForce;
    sq->yForce = yForce + ((physics)? 9.8 : 0);
    sq->xSpeed = xSpeed;
    sq->ySpeed = ySpeed;
    sq->red = red;
    sq->green = green;
    sq->blue = blue;
    sq->alpha = alpha;
    sq->physics = physics;
    sq->update = update;
    list_ins_next(&rectangles, NULL, sq);
}

