// Assignment 4 Graded Participation.cpp 
/*
The local taqueria wants you to write a program which tracks the number of burritos they sell  and help them analyze their business.  
There are four types of burritos: carnitas, beef, shrimp, and vegetarian.
Your program should prompt the user for the number of burritos sold of each type, and then print out a report listing total number of burritos sold, and the type of burrito which sold the most.
You must use two parallel 4-element arrays; one array of type string to store the names of the burrito types, and one array of type int to store the number of burritos sold per type.  
You can store the name of the burrito types using an initialization list.
*/
// Danny Chan
// CS110B
// 9/17/2020

#include <iostream>
using namespace std;
int main()
{
    int highestSold = 0;
    const int NUM_TYPES = 4;
    string burritoType[NUM_TYPES] = { "carnitas", "beef", "shrimp", "veggie" }; // first array
    int numSold[NUM_TYPES]; // second array (holds the numbers sold)
    int total;
    total = 0;
    for (int i = 0; i < NUM_TYPES; i++)
    {
        cout << "Enter numbers of " << burritoType[i] << " " << "sold: " << endl;
        cin >> numSold[i];
        total += numSold[i];
    }
    for (int i = 1; i < NUM_TYPES; i++)
    {
        if (numSold[i] > numSold[highestSold])
        {
            highestSold = i;
        }
    }
    cout << "You sold " << total << " burritos today." << endl;
    cout << "The most sold was " << burritoType[highestSold] << endl;
}


