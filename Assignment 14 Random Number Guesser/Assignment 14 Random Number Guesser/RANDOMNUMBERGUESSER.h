#ifndef RANDOMNUMBERGUESSER_H
#define RANDOMNUMBERGUESSER_H

#include <iostream>
#include <ctime>
using namespace std;

class RandomNumberGuesser :public NumberGuesser
{
private:
	int midpoint;
	bool randomCheck;
public:
	RandomNumberGuesser(int l, int h) :NumberGuesser(l, h)
	{
		srand(time(NULL));
		low = originalLow = l;
		high = originalHigh = h;
		randomCheck = true;
		midpoint = getCurrentGuess();
	}

	virtual int getCurrentGuess()
	{
		if (randomCheck == true && (low <= high))
		{
			midpoint = rand() % (high - low + 1) + low;
			randomCheck = false;
			return midpoint;
		}
		else
			return midpoint;
		return midpoint;
	}

	virtual void higher()
	{
		low = getCurrentGuess() + 1;
		randomCheck = true;
	}

	virtual void lower()
	{
		high = getCurrentGuess() - 1;
		randomCheck = true;
	}

	virtual void reset()
	{
		low = originalLow; high = originalHigh;
	}
};

#endif

