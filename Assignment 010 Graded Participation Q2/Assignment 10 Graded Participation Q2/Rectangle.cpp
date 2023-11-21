#include <iostream>
#include "Rectangle.h"
using namespace std;

void Rectangle::setWidth(double w)
{
    width = w;
}

void Rectangle::setLength(double l)
{
    length = l;
}

double Rectangle::getArea() const
{
    return (length * width);
}

double Rectangle::getPerimeter()
{
    return ((2 * width) + (2 * length));
}

bool Rectangle::isSquare()
{
    return (width == length);
}
