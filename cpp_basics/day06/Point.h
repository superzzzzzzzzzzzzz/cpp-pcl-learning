// Point.h

#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x;
    float y;
    float z;

public:

    Point(float x_, float y_, float z_);

    float getX();
    float getY();
    float getZ();

    void setX(float value);

};

#endif