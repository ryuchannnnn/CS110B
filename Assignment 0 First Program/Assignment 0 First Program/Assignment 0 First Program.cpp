// Assignment 0 First Program.cpp 
// Danny Chan CS110B 
// This program prints out however many asteriks the user wants. 

#include <iostream>
using namespace std;

int main()
{
    int count;
    char goAgain = 'y';
    while (goAgain != 'n')
    {
        cout << "How many asterisks?: ";
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Go again? (y/n): ";
        cin >> goAgain;
    }
    return 0;
}


/*[dchan89@hills ~]$ . / a.out
How many asterisks ? : 5
* ****
Go again ? (y / n) : y
How many asterisks ? : 2
* *
Go again ? (y / n) : n
*/