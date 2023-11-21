// Assignment 7 Graded Participation.cpp
/*
The local taqueria wants you to write a program which tracks the number of burritos they sell each day and help them analyze their business.  
Unlike last time, they don't know the types of burritos they will sell, or how many types of burritos there are, until the day of sale.  Your main() should:
- ask the user for the number of different burrito types sold
- get the names of types from the user, e.g. "carnitas", "chicken", "vegetarian", etc., and ask the user for the number of burritos sold of each type of that day.  
To store all this, you must use two dynamically allocated arrays (i.e. use new to allocate memory for them, and delete [] to delete them when finished).  
You need one string array to store the names of the burrito types, and one int array to store the number of burritos sold.
The string pointer burritosPtr points to the first element of an array of burrito type strings, the int pointer salesPtr points to the first element an array of sales per type, and the int numTypes is how many elements in each array.  
The function prints out a daily report listing sales for each burrito type and total number of burritos sold.  
Call this function from main() with your pointers to demonstrate their usage.
Finally, create a function which will take a string pointer, an int pointer, and an int indicating the number of types as parameters.
*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void printReport(string*, int*, int);

int main()
{
    int numTypes;
    string* burritoNames = NULL;
    int* burritoSales = NULL;
    cout << "Enter the number of different burrito types sold: ";
    cin >> numTypes;
    burritoNames = new string[numTypes];

    for (int i = 0; i < numTypes; i++)
    {
        cout << "What is the name of the burrito " << i + 1 << "?: ";
        cin >> burritoNames[i];
    }
    cout << "Enter number of sales for each burrito:\n";
    burritoSales = new int[numTypes];

    for (int i = 0; i < numTypes; i++)
    {
        cout << burritoNames[i] << " sales: ";
        cin >> burritoSales[i];
    }
    printReport(burritoNames, burritoSales, numTypes);
    delete[] burritoNames;
    delete[] burritoSales;
    burritoNames = NULL;
    burritoSales = NULL;
}

void printReport(string* burritosPtr, int* salesPtr, int numTypes)
{
    cout << "\nSales Report\n";
    int total = 0;
    for (int i = 0; i < numTypes; i++)
    {
        cout << burritosPtr[i] << " sold: " << salesPtr[i] << endl;
        total += salesPtr[i];
    }
    cout << "Total sales: " << total << endl;
}

