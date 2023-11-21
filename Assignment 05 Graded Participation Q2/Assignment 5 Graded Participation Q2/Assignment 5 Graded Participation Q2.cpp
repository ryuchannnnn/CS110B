// Assignment 5 Graded Participation Q2.cpp 
// The SFPD fraud unit has another assignment for you.  
// They have given you a list of 20 known credit card fraudsters at large, and want you to write a program that can detect 
// if one of them is attempting to purchase something at the local Target store.
// Unfortunately, the SFPD has not sorted the list for you, so your program must sort the list first.
/*
Your program should:
read in the 20 names from the file into an array of 20 string objects
sort the array using either bubble sort or selection sort
ask the user for the last name of a customer who is attempting to use a credit card.
search your array to see if this name is on the fraudster list.  
*/
// Danny Chan 
// CS110B
// 9/23/2020


#include <iostream>
#include <fstream>
using namespace std;

void sort(string names[])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = i + 1; j < 20; j++)
        {
            if (names[j] < names[i])
            {
                string temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

bool search(const string names[], string nameSearched)
{
    bool isFound = false;
    int pos = 0;

    while (isFound == false && pos < 20)
    {
        if (names[pos] == nameSearched)
            isFound = true;
        pos++;
    }
    return isFound;
}


int main()
{
    string names[20];
    ifstream inputFile;
    inputFile.open("names.txt");
    if (!inputFile)
    {
        cout << "Error: Invalid filename." << endl;
        exit(1);
    }
    for (int i = 0; i < 20; i++)
    {
        inputFile >> names[i];
    }
    sort(names);
    string nameSearched;
    cout << "Enter the last name of a customer who is attempting to use a credit card:";
    cin >> nameSearched;
    if (search(names, nameSearched))
    {
        cout << "This name is on the fraudster list." << endl;
    }
    else
    {
        cout << "This name is not on the fraudster list." << endl;
    }
    return 0;
}