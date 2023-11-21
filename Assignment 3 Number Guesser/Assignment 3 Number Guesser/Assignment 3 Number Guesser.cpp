// Assignment 3 Number Guesser.cpp 
// In this assignment you will write a program that can figure out a number chosen by a human user.
// The human user will think of a number between 1 and 100.
// The computer program will make guesses and the user will tell the program to guess higher or lower.
// CS110B
// Danny Chan 
// 9/10/2020

#include <iostream>
using namespace std;

// calling functions here in advance 
int getMidpoint(int low, int high);
char getUserResponseToGuess(int guess);
void playOneGame();
bool shouldPlayAgain();

// main function that runs program

int main()
{
	do
	{
		playOneGame();
	} 
	while (shouldPlayAgain());

	return 0;
}

// this function gets the midpoint, and then returns the midpoint
// After returning the midpoint, this midpoint gets plugged into guess
// It gets plugged into guess because guess needs to be an int,
// where we ask the user is it the midpoint the computer calculates
int getMidpoint(int low, int high)
{
	int midpoint;
	midpoint = (low + high)/ 2;
	return midpoint;
}

// this function gets the user input of higher, lower, or correct, and returns the user input.
char getUserResponseToGuess(int guess)
{
	char userInput;
	cout << "Is it " << guess << " " << ("h,l,c") << endl << "h means higher than " << guess << endl; 
	cout << "l means lower than "<< guess << endl; 
	cout << "c meants correct " << endl;
	cin >> userInput;
	return userInput;
}

void playOneGame()
{
	int minValue, maxValue, midpoint;
	char userInput;
	minValue = 1;
	maxValue = 100;
	cout << "Think of a number between 1 and 100." << endl;
	midpoint = getMidpoint(minValue, maxValue);
	userInput = getUserResponseToGuess(midpoint);
	do
	{
		if (userInput == 'h')
		{
			minValue = midpoint + 1; // this means that the user's number is higher than what the computer said
			// we do not need to change maxValue because it is will now be in between the max value and the midpoint
			midpoint = getMidpoint(minValue, maxValue); // gets midpoint on new numbers 
			userInput = getUserResponseToGuess(midpoint); // sends the midpoint into asking the user about new midpoint and if the input is not c, it will check if it is h or l 
		}
		if (userInput == 'l')
		{
			maxValue = midpoint - 1; // this means that the user number is lower than what the computer said 
			// we do not need to change the min value because it will now be between the midpoint and the minvalue 
			midpoint = getMidpoint(minValue, maxValue); // gets midpoint on new numbers 
			userInput = getUserResponseToGuess(midpoint); // sends the midpoint into asking the user about new midpoint and if the input is not c, it will check if it is h or l 
		}
	} 
	while (userInput != 'c');
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
[dchan89@hills ~]$ ./a.out
Think of a number between 1 and 100.
Is it 50 h,l,c
h means higher than 50
l means lower than 50
c meants correct
h
Is it 75 h,l,c
h means higher than 75
l means lower than 75
c meants correct
h
Is it 88 h,l,c
h means higher than 88
l means lower than 88
c meants correct
l
Is it 81 h,l,c
h means higher than 81
l means lower than 81
c meants correct
c
Do you want to play again? (y/n)
y
Think of a number between 1 and 100.
Is it 50 h,l,c
h means higher than 50
l means lower than 50
c meants correct
l
Is it 25 h,l,c
h means higher than 25
l means lower than 25
c meants correct
h
Is it 37 h,l,c
h means higher than 37
l means lower than 37
c meants correct
c
Do you want to play again? (y/n)
n

*/
