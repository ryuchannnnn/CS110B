#include <iostream>
#include "Rectangle.h"
using namespace std;
// set the width of the rectangle
void Rectangle::setWidth(double w)
{
	if (w > 0)
		width = w;
	else
	{
		cout << "ERROR: invalid width!\n";
		exit(1);
	}
}
// set the length of the rectangle
void Rectangle::setLength(double l)
{
	length = l;
	if (l > 0)
		length = l;
	else
	{
		cout << "ERROR: invalid length!\n";
		exit(1);
	}
}
//get the width of the rectangle
double Rectangle::getWidth() const
{
	return width;
}
double Rectangle::getLength() const
{
	return length;
}
double Rectangle::getArea()const
{
	return (length * width);
}
double Rectangle::getPerimeter() const
{
	return ((2 * width) + (2 * length));
}
bool Rectangle::isSquare() 
{
	if (getLength() == getWidth())
	{
		return true;
	}
	else
	{
		return false;
	}
}