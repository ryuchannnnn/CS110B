// Assignment 9 The League with Structs.cpp 
// Danny Chan
// CS 110B
// 10/23/2020

/*
Rewrite your league application from Assignment 5 so that each team/wins pair is stored in a struct named WinRecord.  
Your program must meet the following requirements:
1.  The WinRecord struct must have two fields: an int named wins, and a char* named name.  
name will point to a dynamically allocated array of characters, see requirement 4 below.

2.  Instead of using two parallel arrays like Assignment 6, the data must be stored in a single array -- a dynamically allocated array of WinRecord structs.  
You must ask the user how many teams are in the league to determine how big this array needs to be and then dynamically allocate memory for it using the new operator.  
It must deallocate the memory when it is done with the array using delete [].

3.  Your program must use three functions that accept the array of WinRecord structs by address (i.e., pass a WinRecord pointer):

4. Note that the name field of each WinRecord struct is just a char* which you need to use to store a C-String.  
For this assignment, you must use C-strings, not C++ string objects.  
Unlike a C++ string object, the memory to store the actual character array for the C-String is not allocated for you automatically!  
I encourage you to develop a function to do this on your own, but I have provided the getLine() function https://fog.ccsf.edu/~mluttrel/cs110b/getline.cpp to use if you wish.  
Note that this function returns a line of text from the keyboard contained in a dynamically allocated array.  
You will thus need to deallocate this memory using delete [] when you are done using any arrays you allocated using this function.  
Towards the end of main() is a reasonable place to do this allocation.  
Note that this is in addition to deallocating the array of WinRecord structs discussed in step 2 above!

*/

#include <cstring>
#include <iostream>
using namespace std;

struct WinRecord
{
    int wins;
    char* name;
};

// read in a line of text and return it in a dynamically allocated array
char* getLine()
{
    const int BUFFER_SIZE = 1000;
    // Allocate a buffer local to this function
    char buffer[BUFFER_SIZE];
    // Use cin.getline() to input the buffer from the user
    cin.getline(buffer, BUFFER_SIZE);
    // Find the length of the string in buffer
    int length = strlen(buffer);
    // Dynamically allocate an array, to be returned
    char* rValue = new char[length + 1];
    // Copy the string into the dynamically allocated array
    strncpy(rValue, buffer, length);
    // Return the address of the dynamically allocated array
    return rValue;
}

// Asks the user how many team names, and since we can c - string this
// for wins, since it is an int, we can use cin

void initializeData(WinRecord* standings, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter team name: " << endl;
        standings[i].name = getLine();
        cout << "Enter wins for " << standings[i].name << ": " << endl;
        cin >> standings[i].wins;
        cin.ignore(100, '\n');
    }
}

// Sorts the data in struct and if a previous element is bigger, we swap the positions

void sortData(WinRecord* standings, int size)
{
    WinRecord temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (standings[j].wins < standings[i].wins)
            {
                temp = standings[i];
                standings[i] = standings[j];
                standings[j] = temp;
            }
        }
    }
}

// prints out the sorted data where left is the name and right is the amount of wins

void displayData(WinRecord* standings, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << standings[i].name << " : " << standings[i].wins << endl;
    }
}

int main()
{
    int size;
    WinRecord* standings = NULL;
    cout << "Enter # of teams." << endl;
    cin >> size;
    cin.ignore(100, '\n'); // need this because of getline and cin 
    standings = new WinRecord[size]; // dynamic memory allocation 
    initializeData(standings, size);
    sortData(standings, size);
    displayData(standings, size);
    delete[] standings; // deleting the memory 
    standings = NULL;
    return 0;
}

/*
[dchan89@hills ~]$ ./a.out
Enter # of teams.
4
Enter team name:
Padres
Enter wins for Padres :
56
Enter team name:
49ers
Enter wins for 49ers :
22
Enter team name:
Giants
Enter wins for Giants :
97
Enter team name:
Sharks
Enter wins for Sharks :
18
Sharks : 18
49ers : 22
Padres : 56
Giants : 97
*/
