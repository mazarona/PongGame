#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

typedef struct Line{
    float x1;
    float x2;
    float y1;
    float y2;
    float thickness;
    float xSpeed;
    float ySpeed;
}Line;

typedef struct Square{
    float x;
    float y;
    int size;
    float xSpeed;
    float ySpeed;
    int red;
    int green;
    int blue;
    int alpha;
    void (*update)(struct Square *);
}Square;

typedef struct Rectangle{
    float x;
    float y;
    int widt;
    int hight;
    float xSpeed;
    float ySpeed;
}Rectangle;

#endif
