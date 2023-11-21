// Assignment 1 Ages.cpp : 
// Write a full C++ program which asks the user to input their age, and then tells the user if they are a child, a teen, an adult, or a retiree.
// A child is defined as age at most 12.  A teen is defined as age at least 13 and at most 17.  An adult is defined as age at least 18 and at most 64.
// A retiree is defined as age at least 65.  If the user types in a negative age, your program should tell the user that a negative age is an error! 
// Danny Chan CS110B
//
#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    if (0 <= age && age <= 12)
    {
        cout << "You are a child.";
    }
    else if (13 <= age && age <= 17)
    {
        cout << "You are a teen.";
    }
    else if (18 <= age && age  <= 64)
    {
        cout << "You are an adult.";
    }
    else if (age >= 65)
    {
        cout << "You are a retiree.";
    }
    else if (0 > age)
    {
        cout << "Error! Age must be at least 0!";
    }
    return 0;
}

/*
[dchan89@hills ~]$ ./a.out
Please enter your age: 18
You are an adult.[dchan89@hills ~]$ ./a.out
Please enter your age: 15
You are a teen.[dchan89@hills ~]$ ./a.out
Please enter your age: 3
You are a child.[dchan89@hills ~]$ ./a.out
Please enter your age: -5
Error! Age must be at least 0![
*/