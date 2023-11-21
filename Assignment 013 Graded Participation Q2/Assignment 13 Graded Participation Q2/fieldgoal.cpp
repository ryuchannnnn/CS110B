#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "FieldGoal.h"
using namespace std;

Person::Person(string fName, string lName, FeetInches h, int w, FieldGoal i) {
	firstName = fName;
	lastName = lName;
	height = h;
	weight = w;
	percent = i;
}

void Person::print() {
	cout << firstName << " " << lastName;
	cout << "\nHeight: " << height.getFeet();
	cout << "\'" << height.getInches() << "\"\n";
	cout << "Weight: " << weight << " lb.\n";
	cout << "Field Goal Percentage: " << percent.operator double() << endl;
}

FeetInches::operator double() {
	return feet + (inches / 12.0);
}
FeetInches::operator int() {
	return feet;
}

FieldGoal::operator double() {
	return (double)goals / attempts;
}
