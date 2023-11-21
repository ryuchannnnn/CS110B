// Assignment 4 Graded Participation Q2.cpp
/*
The local taqueria now wants some help with their kitchen system.  There are the same four types of burritos as question 1: carnitas, beef, shrimp, and vegetarian.  
They would like you to create a program to send an alert to the kitchen if there is a shrimp burrito in a given order.
Your main() function should prompt the user for the number of burritos in the order, and then enter all the burrito types for the order.  The burrito types should be stored in an array of strings.  You'll also need to store the number of burritos in the order.  
You can assume that no order will have more than 10 burritos.  
You can assume that the user only types in valid types of burritos, e.g. carnitas, beef, shrimp, vegetarian.
The shrimp burrito must be cooked to order and thus takes longer to prepare than the other kinds.  
Because of this, an alert is needed ASAP if there is a shrimp burrito in the order.   
Write a function which takes two parameters: your array of burrito strings, and the number of burritos in the array.  
It should determine if there are any shrimp burritos in the array and print out an alert if so.  
You must write a function for this alert, this can't be in main().
*/

#include <iostream>

using namespace std;

const int orderCap = 10;

void hasShrimp(string[], int);

int main()
{
    string burritoOrder[orderCap];
    cout << "How many burritos are in the order? ";
    int numBurritos;
    cin >> numBurritos;

    for (int i = 0; i < numBurritos; i++)
    {
        cout << "What is burrito " << i + 1 << "? ";
        cin >> burritoOrder[i];
    }
    hasShrimp(burritoOrder, numBurritos);
}

void hasShrimp(string burritoList[], int numBurritos)
{
    for (int i = 0; i < numBurritos; i++)
    {
        if (burritoList[i] == "shrimp")
        {
            cout << "This order has shrimp!" << endl;
            return;
        }
    }
    cout << "No shrimp in order!" << endl;
}
