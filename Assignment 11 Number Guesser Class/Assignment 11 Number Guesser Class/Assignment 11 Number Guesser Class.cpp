// Assignment 11 Number Guesser Class.cpp
// Danny Chan 
// CS110B
// 11/7/2020

// For this assignment you will write up code for the same number guessing game you implemented in a previous assignment, in which the user picks a number, and your program tries to guess the number.  Each time that the program guesses a number the user responds by telling the program either the correct answer is higher or lower, or that the program’s guess is correct.
/*
When a new instance of a NumberGuesser class is created the upper and lower bounds of the possible values should be passed into its constructor.  From that point on, a NumberGuesser object will always return the midpoint of the possible values when the getCurrentGuess() member function is called.  If the higher() or lower() member functions are called, the NumberGuesser object should adjust its private variables to represent the new possible range of values.
For example, if a NumberGuesser is created with the following line of code then the range will be the numbers from 1 to 100:
*/
/*
If the getCurrentGuess() method is called it should return 50, which is the midpoint between 1 and 100.  If the higher() method is then called, the object should adjust its state accordingly so that it knows that the correct value is now between 51 and 100, inclusive, and getCurrentGuess() would now return 75, the midpoint between 51 and 100.  If the lower() method is then called, it should adjust its state to represent that the possible values are now between 51 and 74, and getCurrentGuess() should return 62, the midpoint between 51 and 74.  By following this strategy the number guesser should be able to eventually guess the proper value that the user guessed.
As another example, here a different NumberGuesser is created with range between 25 and 35:
The reset() method should return a NumberGuesser object to the state that it was in when it was constructed, i.e. with its original lowerBound and upperBound reset back to their original values.  This allows reusing this same NumberGuesser object to play a new game.  Hint: you can create extra member variables in your class to store these original values.
Note: Your NumberGuesser class should not contain any cin or cout statements.  It is only responsible for handling the indicated methods.  All of the input and output work should be handled elsewhere in your program, e.g. in main().
*/

#include <iostream>
#include "NumberGuesser.h"
using namespace std;

bool shouldPlayAgain();

int main()
{
    do
    {
        char userResponse = 'z';
        NumberGuesser nG(1, 100);
        cout << "Think of a number between 1 and 100" << endl;
        cout << "Is it " << nG.getCurrentGuess() << "?" << endl;
        cout << ("h,l,c") << endl << "h means higher than " << nG.getCurrentGuess() << endl;
        cout << "l means lower than " << nG.getCurrentGuess() << endl;
        cout << "c meants correct" << endl;
        cin >> userResponse;
        do
        {
            if (userResponse == 'h')
            {
                cout << "higher than " << nG.getCurrentGuess() << endl;
                nG.higher();
                cout << "Is it " << nG.getCurrentGuess() << "?" << endl;
                cin >> userResponse;
            }
            if (userResponse == 'l')
            {
                cout << "lower than " << nG.getCurrentGuess() << endl;
                nG.lower();
                cout << "Is it " << nG.getCurrentGuess() << "?" << endl;
                cin >> userResponse;
            }
        } while (userResponse != 'c');
        cout << "You guessed " << nG.getCurrentGuess() << " Nice!" << endl;
    } while (shouldPlayAgain());
    return 0;
}

bool shouldPlayAgain()
{
    char playAgain;
    cout << "Do you want to play again? (y/n)" << endl;
    cin >> playAgain;
    if (playAgain == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
[dchan89@hills ~]$ g++ Assignment11NumGuesser.cpp Numberguesser.o
[dchan89@hills ~]$ ./a.out
Think of a number between 1 and 100
Is it 50?
h,l,c
h means higher than 50
l means lower than 50
c meants correct
h
higher than 50
Ok...
Is it 75?
l
lower than 75
Ok...
Is it 62?
h
higher than 62
Ok...
Is it 68?
h
higher than 68
Ok...
Is it 71?
h
higher than 71
Ok...
Is it 73?
l
lower than 73
Ok...
Is it 72?
c
You guessed 72 Nice!
Do you want to play again? (y/n)
y
Think of a number between 1 and 100
Is it 50?
h,l,c
h means higher than 50
l means lower than 50
c meants correct
l
lower than 50
Ok...
Is it 25?
c
You guessed 25 Nice!
Do you want to play again? (y/n)
n
[dchan89@hills ~]$
*/