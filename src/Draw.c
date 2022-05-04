#include <SDL2/SDL.h>
#include "../include/LinkedList.h"
#include "../include/GameObjects.h"
#include "../include/globals.h"

void drawRectangles(void)
{
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
}

void drawLines(void)
{
    for(List_elmt *temp = lines.head; temp != NULL; ){
        Line *line = ((Line *)temp->data);
        SDL_Point point1 = {line->x1, line->y1};
        SDL_Point point2 = {line->x2, line->y2};
        SDL_SetRenderDrawColor(rendererGlobal, line->red, line->green, line->blue, line->alpha);
        for(int i =0; i < line->thickness; i++)
        {
            SDL_RenderDrawLineF(rendererGlobal, point1.x, point1.y, point2.x,point2.y);
            point1.x += 1;
            point2.x += 1;
        }
        temp = temp->next;
    }
}
void draw(void)
{
    SDL_SetRenderDrawColor(rendererGlobal, 0, 0, 0, 255);
    SDL_RenderClear(rendererGlobal);
    drawLines();
    drawRectangles();
    SDL_RenderPresent(rendererGlobal);
}
