// Assignment 03 Graded Participation.cpp 
// To convert between Celsius and Fahrenheit, the following formula is used, where C = Celsius temperature and F = Fahrenheit temperature:
// C = 5/9 * (F-32)
// Write a C++ temperature conversion program which does the following:
// Write a function called toCelsuis which takes a Fahrenheit temperature as a parameter, and returns the equivalent Celsius temperature: float toCelsius(float) 
// Demonstrate that your function works by writing a main() function that prints out a conversion table. It should have Fahrenheit values 60, 61, 62, ... through 80
// If you like: you can add this line in your function to make floating point output fixed, make sure you #include<iomanip>
// If you like: you can then call setprecision(1) in your cout statements to print out one decimal place, e.g.
// Danny Chan 
// CS110B
// 9/9/2020


#include <iostream>
#include<iomanip>
using namespace std;

float toCelsius(float Fahrenheit)
{
    float Celsius;
    Celsius = ((float)5 / 9) * (Fahrenheit - 32);
    cout.setf(ios::fixed, ios::floatfield);
    cout << setprecision(1) << Fahrenheit;
    cout << "    ";
    cout.setf(ios::fixed, ios::floatfield);
    cout << Celsius << endl;
    return Celsius;
}

int main()
{
    cout << "Welcome to the temperature table!" << endl;
    cout << "F" << "        " << "C" << endl;
    for (float i = 60.0; i <= 80.0; i++)
    {
        toCelsius(i);
    }
}