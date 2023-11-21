// Assignment 9 Graded Participation Q1
// Danny Chan
// CS110B
// 10/22/2020
/*
The local taqueria wants you to write a program which tracks the number of burritos they sell each day and help them analyze their business.
Your program should ask the user for the number of different burrito types sold, then get the names of the types and the number of burritos sold of each type of that day.  
Print out a daily report listing sales for each burrito type and total number of all burritos sold.
So far, this sounds very similar to a previous exercise!  
This difference this time is that you must use a struct called SalesRecord which has two fields -- a string containing the name of the burrito, and an int containing the number of burritos sold of this type.  You must have one dynamically allocated array of SalesRecord structs.
*/

#include <iostream>
using namespace std;

struct SalesRecord
{
    string burritoTypes;
    int numSold;
};

int main()
{
    SalesRecord* sale = NULL;
    int numTypes;
    cout << "How many burrito types today?\n";
    cin >> numTypes;
    sale = new SalesRecord[numTypes];
    for (int i = 0; i < numTypes; i++)
    {
        cout << "Enter type of burrito" << endl;
        cin >> sale[i].burritoTypes;
        cout << "Enter number sold of " << sale[i].burritoTypes << endl;
        cin >> sale[i].numSold;
    }
    cout << "Sales Record for today is:" << endl;
    for (int i = 0; i < numTypes; i++)
    {
        cout << sale[i].burritoTypes << " " << sale[i].numSold << endl;
    }
    delete[] sale;
    sale = NULL;
}