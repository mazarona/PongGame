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
    float xSpeed;
    float ySpeed;
    float xForce;
    float yForce;
    int size;
    float mass;
    int red;
    int green;
    int blue;
    int alpha;
    bool physics;
    void (*update)(struct Square *, float elapsedTime);
}Square;

typedef struct Rectangle{
    float x;
    float y;
    int widt;
    int hight;
    float xSpeed;
    float ySpeed;
}Rectangle;

void createSquare(float x, float y, int size, float xSpeed, float ySpeed, float mass,
        int red, int green, int blue, int alpha, bool physics,void(*update)(struct Square*, float elapsed));

#endif
