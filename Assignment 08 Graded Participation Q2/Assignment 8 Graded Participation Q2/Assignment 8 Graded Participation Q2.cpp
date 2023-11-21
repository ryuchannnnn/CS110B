// Assignment 8 Graded Participation Q2
// Danny Chan
// CS 110B 
// 10/14/2020
/*
Write a function to determine if a C-string begins with a specified prefix.  It should have the following signature:
bool starts(char *str, char *prefix)
t should return true if str begins with prefix, false if not.  
It should return false if prefix is longer than str. 
You can assume that the pointers passed to it are pointers to valid, null-terminated C-Strings.  
If you wish, you can use the strlen() and strcmp() functions, but it's not required.
Hint: it can make things easier to check if length of prefix > length of str.  
If so, you can immediately return false!  
If not, you can continue on with your check.
*/


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool starts(char* str, char* prefix) 
{
    if (strlen(prefix) > strlen(str)) 
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < strlen(prefix); i++) 
        {
            if (prefix[i] != str[i]) 
            {
                return false;
            }
            return true;
        }
    }
}

int main() 
{
    char var1[] = "airplanes";
    char var2[] = "air";
    if (starts(var1, var2) == 1) 
    {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}