// Assignment 11 Graded Participation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle house[] = { Rectangle(10, 12, (char*)"Kitchen"),
                          Rectangle(20, 20, (char*)"Bedroom"),
                          Rectangle(8, 12, (char*)"Offce") };
    house[2].setName((char*)"Office");

    int high = (house[0].getWidth() * house[0].getLength());
    Rectangle* index = &house[0];

    for (int i = 0; i < 3; i++)
    {
        house[i].printName();
        cout << "-area: " << (house[i].getWidth() *
            house[i].getLength()) << endl;
        if ((house[i].getWidth() * house[i].getLength()) > high)
            index = &house[i];
    }
    index->printName();
    cout << " has the largest area.\n";
    return 0;
} // end main