#ifndef NumberGuesser_h
#define NumberGuesser_h
#include <iostream>
using namespace std;
class NumberGuesser
{
private:
    char userResponse;
    int low;
    int initialLow;
    int initialHigh;
    int high;
    int midpointCurrentGuess;
public:
    //constructors
    NumberGuesser();
    NumberGuesser(int lowerBound, int upperBound);
    void higher();
    void lower();
    int getCurrentGuess();
    void reset();
};
#endif
