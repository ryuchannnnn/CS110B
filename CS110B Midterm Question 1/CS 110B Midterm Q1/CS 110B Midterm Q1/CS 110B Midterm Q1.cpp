// CS 110B Midterm Q1.cpp 
// Midterm Question 1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <windows.h>
using namespace std;

void timer(int num);

int main()
{
    int num = 10;
    timer(num);
}

void timer(int num)
{
    while (num > 0)
    {
        for (int i = 0; i <= num; i++)
        {
            for (int j = 60; -1 < j; j--)
            {
                if (j == 60)
                {
                    cout << num << ":" << 0 << endl;
                    num = num - 1;
                }
                else
                {
                    cout << num << ":" << j << endl;
                }
                usleep(1000000); // doesnt work on visual studio code 
            }
        }
    }
}


