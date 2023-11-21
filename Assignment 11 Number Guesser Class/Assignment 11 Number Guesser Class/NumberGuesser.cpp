#include <iostream>
#include "NumberGuesser.h"
using namespace std;
// constructor 
NumberGuesser::NumberGuesser()
{
	int low = 1;
	int initialLow = low;
	int initialHigh = high;
	int high = 100;
	char userResponse;
}
// constructor
NumberGuesser::NumberGuesser(int lowerBound, int higherBound)
{
	low = lowerBound;
	initialLow = low;
	initialHigh = high;
	high = higherBound;
}
void NumberGuesser::higher()
{
	low = midpointCurrentGuess + 1;
}
void NumberGuesser::lower()
{
	high = midpointCurrentGuess - 1;
}
int NumberGuesser::getCurrentGuess()
{
	midpointCurrentGuess = ((low + high) / 2);
	return midpointCurrentGuess;
}
void NumberGuesser::reset()
{
	low = initialLow;
	high = initialHigh;
}