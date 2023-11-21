// Assignment 13 Graded Participation Q1.cpp :
/*
Overload the = operator for your Rectangle class.  As discussed in the pdfs and videos, it should return a Rectangle in order to support multiple assignments in one line, e.g. a = b = c;.  
Copying from the pdfs is acceptable, but make sure you understand how it works.
Overload the < and > operators in Rectangle to determine if one rectangle is bigger than the other, based on area.
Demonstrate that your new operators work by writing a simple main() function to show they work.
*/
// Danny Chan
// CS110B
// 11/20/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Rectangle.h"
using namespace std;

int main()
{
	Rectangle r1(10, 10, "Office");
	Rectangle r2(20, 20, "Bedroom");
	Rectangle r3;
	r3 = r1 + r2;
	cout << r3.getArea() << endl;
	if (r1 > r2)
	{
		cout << "r1 has the greater area." << endl;
	}
	else if (r2 > r1)
	{
		cout << "r2 has the greater area." << endl;
	}
	else
	{
		cout << "r1 and r2 have the same area." << endl;
	}
}