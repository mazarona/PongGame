#include <stdlib.h>
#include <stdbool.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"

/* Keep track of created game objects in a linked list*/
List rectangles;
List lines;

static void destroyRectangles(void *data){free((Rectangle *) data);}
static void destroyLines(void *data){free((Line *) data);}
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
    //      provided destroy function above
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

void createLine(float x1, float y1, float x2, float y2, int thickness, float xSpeed, float ySpeed, float mass, float xForce, float yForce,
        int red, int green, int blue, int alpha, bool physics ,void(*update)(struct Line*, float elapsed))
{
    // Initialize the linked list only once
    static bool initialize = false;
    if(!initialize){
        list_init(&lines, destroyLines);
        initialize = true;
    }
    Line *line = (Line *)malloc(sizeof(Line));
    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;
    line->thickness = thickness;
    line->xSpeed = xSpeed;
    line->ySpeed = ySpeed;
    line->xForce = xForce;
    line->yForce = yForce + ((physics)? 9.8 : 0);
    line->mass = mass;
    line->red = red;
    line->green = green;
    line->blue = blue;
    line->alpha = alpha;
    line->physics = physics;
    line->update = update;
    list_ins_next(&lines, NULL, line);
}
