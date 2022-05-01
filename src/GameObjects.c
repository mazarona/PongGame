#include "../include/GameObjectsPrivate.h"
#include "../include/linked_list.h"
#include <stdlib.h>

/* Keep track of created game objects in a linked list*/
List squares;
static void destroySquares(void *data){free((Square *) data);}

void createSquare(float x, float y, int size, float xSpeed, float ySpeed,
        int red, int green, int blue, int alpha, void(*update)(struct Square*))
{
    list_init(&squares, destroySquares);
    

}

