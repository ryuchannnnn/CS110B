// Assignment 13 Graded Participation Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "FieldGoal.h"
using namespace std;

int main() 
{
	FeetInches height(6, 3);
	FieldGoal score(2, 10);
	Person pointGuard("Stephen", "Curry", height, 190, score);
	pointGuard.print();
}