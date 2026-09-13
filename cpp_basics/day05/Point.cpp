#include "Point.h"


Point::Point(float x_, float y_, float z_)
{
    x = x_;
    y = y_;
    z = z_;
}


float Point::getX()
{
    return x;
}


float Point::getY()
{
    return y;
}


float Point::getZ()
{
    return z;
}


void Point::setX(float value)
{
    x = value;
}