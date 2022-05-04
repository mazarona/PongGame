#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H
#include <stdbool.h>

typedef struct Line{
    float x1;
    float y1;
    float x2;
    float y2;
    float thickness;
    float xSpeed;
    float ySpeed;
    float xForce;
    float yForce;
    float mass;
    int red;
    int green;
    int blue;
    int alpha;
    bool physics;
    void (*update)(struct Line *, float elapsedTime);
}Line;

typedef struct Rectangle{
    float x;
    float y;
    float width;
    float height;
    float widthScale;
    float heightScale;
    float xSpeed;
    float ySpeed;
    float xForce;
    float yForce;
    float mass;
    int red;
    int green;
    int blue;
    int alpha;
    bool physics;
    void (*update)(struct Rectangle *, float elapsedTime);
}Rectangle;

void createSquare(float x, float y, int size, float xSpeed, float ySpeed, float mass, float xForce, float yForce,
        int red, int green, int blue, int alpha, bool physics,void(*update)(struct Rectangle*, float elapsed));

#endif
