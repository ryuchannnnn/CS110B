// Assignment 10 Graded Participation Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* 
Take your Rectangle program from Question 1 and split it into three files:
Rectangle.h - class declaration
Rectangle.cpp - class implementation
RectangleProgram.cpp - main program
Modify your Rectangle program so that getWidth() and getLength() are inline member functions, defined in the class declaration in Rectangle.h.  
The other member functions should be defined in Rectangle.cpp.
Demonstrate your class works with a main function in RectangleProgram.cpp that instantiates a Rectangle object, creates a pointer to this object, 
and uses this pointer to call the member functions.

*/
//

#include <iostream>
#include "Rectangle.h"
using namespace std;
int main()
{
	Rectangle r;
	Rectangle* roomPtr = NULL;
	roomPtr = &r;
	int userWidth, userLength;
	cout << "Enter width: " << endl;
	cin >> userWidth;
	roomPtr->setWidth(userWidth);
	cout << "Enter length: " << endl;
	cin >> userLength;
	roomPtr->setLength(userLength);
	cout << "Your rectangle has area: " << roomPtr->getArea() << " sq ft. " << endl;
	cout << "Your rectangle has perimeter: " << roomPtr->getPerimeter() << " sq ft. " << endl;
	if (roomPtr->isSquare() == true)
	{
		cout << "This is also a square." << endl;
	}
	else
	{
		cout << "This is not a square." << endl;
	}

	return 0;
}