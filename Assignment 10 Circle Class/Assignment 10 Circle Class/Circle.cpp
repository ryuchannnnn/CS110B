#include <iostream>
#include "Circle.h"
#include<cmath>
using namespace std;

void Circle::setRadius(double r)
{
    radius = r;
}

void Circle::setX(double xValue)
{
    x = xValue;
}

void Circle::setY(double yValue)
{
    y = yValue;
}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getX() const
{
    return x;
}

double Circle::getY() const
{
    return y;
}

double Circle::getArea() const
// This member function should return the area of the circle.  When you are calculating the area you can use 3.14 for pi.  The formula is radius * radius * pi.  
{
    return radius * radius * pi;
}

bool Circle::containsPoint(double xValue, double yValue)
/* This member function should return true if the point at (xValue, yValue) is contained in the circle, and false if not.  You can determine whether or not a point is in a circle by calculating the distance from the center of the circle (its x and y coordinates) to the point (parameters xValue, yValue).  If this distance is less than or equal to the radius then the point is inside the circle.  For your reference, here is how to calculate distance between two points */
// https://www.purplemath.com/modules/distform.htm
{
    double xSquare, ySquare, distance;
    xSquare = (xValue - x) * (xValue - x);
    ySquare = (yValue - y) * (yValue - y);
    distance = sqrt(xSquare + ySquare);
    if (distance <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}