#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

#ifndef FIELDGOAL_H
#define FIELDGOAL_H

class FeetInches {
private:
	int feet;
	int inches;
public:
	FeetInches()
	{
		feet = inches = 0;
	}
	FeetInches(int f, int i)
	{
		feet = f; inches = i;
	}
	void setFeet(int f)
	{
		feet = f;
	}
	void setInches(int i)
	{
		inches = i;
	}
	int getFeet()
	{
		return feet;
	}
	int getInches()
	{
		return inches;
	}
	operator double();
	operator int();
};

class FieldGoal {
private:
	int goals;
	int attempts;
public:
	FieldGoal()
	{
		goals = attempts = 0;
	}
	FieldGoal(int g, int a)
	{
		goals = g; attempts = a;
	}
	operator double();
	//{return (double)goals/attempts;}
	//{return goals/attempts*1.0;}
};

class Person {
private:
	string firstName;
	string lastName;
	FeetInches height;
	int weight;
	FieldGoal percent;
public:
	Person()
	{
		firstName = lastName = ""; weight = 0;
	}
	Person(string, string, FeetInches, int, FieldGoal);
	void print();
};

#endif
