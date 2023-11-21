// Midterm Q2.cpp

/*
Write a function which takes two parameters: an array of ints and an int size of the array and prints every element greater than 5 to the screen.  As an example, if the array has the following 10 elements: 2 5 8 9 7 1 0 2 6 3, your function should print out 8 9 7 6.  You may assume that the parameters passed to the function are valid.  Your function must have the following signature:
void printSome(const int array[], int size);
*/

#include <iostream>
using namespace std;

void printSome(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 5)
        {
            cout << array[i];
        }
    }
}

int main()
{
    int size = 10;
    const int array[10] = { 2, 5, 8, 9, 7, 1, 0, 2, 6, 3 };
    printSome(array, size);
}