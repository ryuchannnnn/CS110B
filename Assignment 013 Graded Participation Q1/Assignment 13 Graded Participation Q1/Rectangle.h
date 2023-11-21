#define _CRT_SECURE_NO_WARNINGS
#ifndef Rectangle_h
#define Rectangle_h
#include <iostream>
#include <cstring>
using namespace std;
class Rectangle
{
private:
	double width;
	double length;
	char* name;
	void initName(char* name);
public:
	Rectangle();
	Rectangle(double, double, char*);
	Rectangle(Rectangle&);
	~Rectangle();
	Rectangle& operator=(const Rectangle& r);
	Rectangle operator+(const Rectangle& r)
	{
		Rectangle newRect;
		newRect.width = width + r.width;
		newRect.length = length + r.length;
		newRect.setName(name);
		return newRect;
	}
	bool operator <(const Rectangle& r);
	bool operator >(const Rectangle& r);
	void setWidth(double);
	void setLength(double);
	void setName(char*);
	double getWidth() const;
	double getLength() const;
	void printName() const
	{
		cout << name;
	}
	double getArea() const;
};
#endif