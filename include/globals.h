#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL2/SDL.h>
#include "LinkedList.h"

// Defined in Init.c
extern SDL_Renderer *rendererGlobal;
extern SDL_Window *windowGlobal;

// Defined in GameObjects.c
extern List lines;
extern List rectangles;
extern List polygons;

#endif
