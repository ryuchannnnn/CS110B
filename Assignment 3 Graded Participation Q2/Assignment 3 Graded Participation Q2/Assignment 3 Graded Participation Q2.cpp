// Assignment 3 Graded Participation Q2.cpp
// Write a C++ temperature conversion program which does the following:
// Write a function called toCelsiusByReference, which takes a parameter temperature by reference, and returns a bool:
// bool toCelsiusByReference(float &temperature)
// It should do two things:
//  change the parameter temperature from Fahrenheit to the equivalent Celsius temperature
//  return true if the parameter was was above freezing (>32 F), return false if freezing or below.
// Demonstrate that the function works by writing a main() function that asks the user to input any Fahrenheit temperature, calling the function to convert,
// and then printing out the celsius temperature.  Also, use the bool returned from the function to print out a message saying if it's above freezing or not. 
// Your cout statements must all be in main(), they must not be in your function.
// 


#include <iostream>
#include<iomanip>
using namespace std;

bool toCelciusByReference(float&);

int main()
{
    float temperature;
    cout << "Welcome to the temperature converter!" << endl;
    cout << "Please enter a temperature in Fahrenheit: ";
    cin >> temperature;
    bool aboveFreezing = toCelciusByReference(temperature);
    cout.setf(ios::fixed, ios::floatfield);
    cout << "The equivalent Celsius is: " << setprecision(1) << temperature << endl;

    if (aboveFreezing)
    {
        cout << "The temperature is above freezing." << endl;
    }
    else
    {
        cout << "The temperature is freezing or below." << endl;
    }
}

bool toCelciusByReference(float& temperature)
{
    temperature = (((temperature - 32) * 5) / 9);

    return temperature > 0;
}