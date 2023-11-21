// Rectangle.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;

void Rectangle::initName(char* n)
{
    name = new char[128];
    strcpy(name, n);
}

Rectangle::Rectangle()
{
    width = length = 0;
    initName((char*)"Default");
}

Rectangle::Rectangle(double w, double l, char* n)
{
    width = w;
    length = l;
    initName(n);
}

Rectangle::~Rectangle()
{
    delete[] name;
    name = NULL;
}

void Rectangle::setWidth(double w)
{
    if (w > 0)
        width = w;
    else
        cout << "ERROR! Invalid width!\n";
    exit(1);
}

void Rectangle::setLength(double l)
{
    if (l > 0)
        length = l;
    else
        cout << "ERROR! Invalid length!\n";
    exit(1);
}

void Rectangle::setWidth(char* w)
{
    double myWidth = atof(w);
    if (myWidth > 0)
        width = myWidth;
    else
        cout << "ERROR! Invalid width!\n";
    exit(1);
}

void Rectangle::setLength(char* l)
{
    double myLength = atof(l);
    if (myLength > 0)
        length = myLength;
    else
        cout << "ERROR! Invalid length!\n";
    exit(1);
}

void Rectangle::setName(char* n)
{
    strcpy(name, n);
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getLength() const
{
    return length;
} // end Rectangle.cpp
