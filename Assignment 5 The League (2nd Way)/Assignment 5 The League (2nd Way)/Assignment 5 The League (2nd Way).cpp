// Assignment 5 The League.cpp
/*
Write a program that records and displays league standings for a baseball league.
The program will ask the user to enter five team names, and five win amounts.
It will store the data in memory, and print it back out sorted by wins from highest to lowest.
*/
// Danny Chan
// CS110B
// 9/25/2020


#include <iostream>
using namespace std;

void initializeArrays(string names[], int wins[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter team #" << i + 1 << ":" << endl;
        cin >> names[i];
        cout << "Enter wins for " << names[i] << ":" << endl;
        cin >> wins[i];
    }
}

void sortData(string names[], int wins[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (wins[i] < wins[j])
            {
                swap(wins[i], wins[j]);
                swap(names[i], names[j]);
            }
    }
}

void displayData(string names[], int wins[], int size)
{
    cout << "The league standings are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << ":" << wins[i] << endl;
    }
}

int main()
{
    const int size = 5;
    string names[size];
    int wins[size];
    initializeArrays(names, wins, size);
    sortData(names, wins, size);
    displayData(names, wins, size);
}
