// Assignment 14 Random Number Guesser.cpp
// Danny Chan
// CS110B
// 12/7/2020
/*
Write a derived class of the NumberGuesser class named RandomNumberGuesser.  
The derived class should override the behavior of the getCurrentGuess method.  It may also add member data and its own constructor.  
It may also override the higher(), lower() and reset() methods as you see fit.
To get everyone started off on the same page I have written a NumberGuesser class.  
It is defined entirely in-line in the following file:
In the current NumberGuesser class the getCurrentGuess() method returns the midpoint of the range of possible values.  
In your RandomNumberGuesser class the getCurrentGuess() method should return a randomly generated number in the range of possible values.

Note that repeated calls to getCurrentGuess() should always return the same value for both classes if neither the higher() or the lower() functions are called
Each invocation of getCurrentGuess should return 5. This value does not change until the higher() or lower() function is called.

Now consider a RandomNumberGuesser example.  The first call to getCurrentGuess() should return a random number between 1 and 10, inclusive. 
Each subsequent call to getCurrentGuess() should return the same number, until higher() or lower() is called, at which point a new random number within the new range should be generated.

Make careful note of how the word “virtual” is used in NumberGuesser.h!
*/
//

#include <iostream>
#include <ctime>
#include "NumberGuesser.h"
#include "RandomNumberGuesser.h"
using namespace std;

void guesser(NumberGuesser* ngPtr)
{
	char response = 'a';

	while (tolower(response) != 'c')
	{
		cout << "Guess: " << ngPtr->getCurrentGuess() << endl;
		cout << "(h/l/c)\n";
		cin >> response;

		if (tolower(response) == 'h')
			ngPtr->higher();
		else if (tolower(response) == 'l')
			ngPtr->lower();
	}
}

bool playAgain()
{
	char response;

	cout << "Play again (y/n)\n";
	cin >> response;

	if (tolower(response) == 'y')
		return true;
	else
		return false;
}

int main()
{
	bool playGame = true;
	NumberGuesser* ngPtr = new RandomNumberGuesser(1, 10);

	do
	{
		guesser(ngPtr);
		playGame = playAgain();
		ngPtr->reset();
		cout << endl;
	} while (playGame);

	return 0;
}

