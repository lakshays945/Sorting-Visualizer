#pragma once
#include <math.h>
class Vector2D{
public:
    float x,y;
    //constructors
    Vector2D(float x, float y)
    : x(x), y(y){}
    Vector2D(){
        x = 0;
        y = 0;
    }
    Vector2D operator+(const Vector2D &other){
        return Vector2D(x+other.x,y+other.y);
    }
    Vector2D operator-(const Vector2D &other){
        return Vector2D(x-other.x,y-other.y);
    }
};