#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Rectangle.h"
#include <cstring>
using namespace std;

// constructor 
Rectangle::Rectangle()
{
	width = length = 0;
	name = new char[128];
}

//constructor with parameters
Rectangle::Rectangle(double w, double l, char* n)
{
	cout << "In the constructor" << endl;
	width = w;
	length = l;
	name = new char[128];
	strcpy(name, n);
}

//Copy Constructor
Rectangle::Rectangle(Rectangle& r)
{
	width = r.width;
	length = r.length;
	initName(r.name);
}

//destructor
Rectangle::~Rectangle()
{
	cout << "In the Destructor" << endl;
	delete[] name;
	name = NULL;
}

// overloaded = operator
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	length = r.length;
	width = r.width;
	strcpy(name, r.name);
	return *this;
}
// overloaded < operator
bool Rectangle::operator<(const Rectangle& r)
{
	if (getArea() < r.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// overloaded > operator
bool Rectangle::operator>(const Rectangle& r)
{

	if (getArea() > r.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// initializting the name with c-string
void Rectangle::initName(char* n)
{
	name = new char[128];
	strcpy(name, n);
}

// setters 
void Rectangle::setName(char* n)
{
	strcpy(name, n);
}

void Rectangle::setWidth(double w)
{
	if (w > 0)
	{
		width = w;
	}
	else
	{
		cout << "Error! Invalid width! \n";
		exit(1);
	}
}

void Rectangle::setLength(double l)
{
	if (l > 0)
	{
		length = l;
	}
	else
	{
		cout << "Error! Invalid length! \n";
		exit(1);
	}
}
// getters
double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getArea() const
{
	return length * width;
}