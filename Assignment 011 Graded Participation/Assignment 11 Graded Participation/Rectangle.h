// Rectangle.h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle
{
private:
    double width;
    double length;
    char* name;
    void initName(char*);
public:
    Rectangle();
    Rectangle(double, double, char*);
    ~Rectangle();
    void setWidth(double);
    void setLength(double);
    void setWidth(char*);
    void setLength(char*);
    void setName(char*);
    double getWidth() const;
    double getLength() const;
    void printName() const
    {
        cout << name;
    }
};

#endif // end Rectangle.h

