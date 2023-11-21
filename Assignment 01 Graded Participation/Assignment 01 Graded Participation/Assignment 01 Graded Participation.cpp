// Assignment 01 Graded Participation.cpp
// A simple driver program in C++,
// Output a statement to ask the user to input the numbers of innings today's pitcher pitched.  Store the user's response in a variable numInnings of type int
// Output a statement to ask the user to input the numbers of runs today's pitcher gave up.  Store the user's response in another variable numRuns of type int
// Calculate the pitcher's ERA using the following formula: ERA = numRuns * 9 / numInnings
// Output the ERA to the screen
// Put your code below after the line which says "// insert your code here" 
// Danny Chan, CS110B

#include <iostream>
using namespace std;

int main()
{
    int numInnings, numRuns;
    float ERA;
    cout << "Number of innings today's pitcher pitched: ";
    cin >> numInnings;
    cout << "Number of runs today's pitcher gave up: ";
    cin >> numRuns;
    ERA = (((float)numRuns * 9) / (float)(numInnings));
    cout << "ERA = " << ERA;
}   
