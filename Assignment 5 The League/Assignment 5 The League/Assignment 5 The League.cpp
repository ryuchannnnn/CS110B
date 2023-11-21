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

void stringSwitcher(string& abcd, string& defg)
{
    string switcher = "switch";
    switcher = abcd;
    abcd = defg;
    defg = switcher;
}

void winsSwitcher(int& a, int& b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

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
                winsSwitcher(wins[i], wins[j]);
                stringSwitcher(names[i], names[j]);
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

/*
[dchan89@hills ~]$ ./a.out
Enter team #1:
Padres
Enter wins for Padres:
75
Enter team #2:
Dodgers
Enter wins for Dodgers:
91
Enter team #3:
Giants
Enter wins for Giants:
92
Enter team #4:
Rockies
Enter wins for Rockies:
65
Enter team #5:
Diamondbacks
Enter wins for Diamondbacks:
70
The league standings are:
Giants:92
Dodgers:91
Padres:75
Diamondbacks:70
Rockies:65
*/