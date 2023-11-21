// Assignment 2 Blackjack.cpp
// Write a C++ program that plays a simplified version of blackjack where we don’t worry about aces and face cards.
// The program should generate a random number between 1 and 10 each time the player gets a card. 
// It should display a running total of the players cards, and ask the player whether or not it should deal another card. 
// If the player goes over 21, your program should tell the player he is bust, and the current hand is over, and the dealer wins. 
// At the end of the hand, your program should ask the player if he would like to play again.
// Danny Chan 
// CS110B 
// 9/2/2020

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	cout << "Welcome to Blackjack." << endl;
	cout << "You will start with 2 cards with a random value of 1 to 10." << endl;
	cout << "Your goal is to get as close to 21 as possible." << endl;
	cout << "If you go over 21, you bust, and the game is over." << endl;
	const int minValue = 1;
	const int maxValue = 10;
	const int bust = 21;
	int playerCard1, playerCard2, total;
	string anotherCard, playAgain;
	do
	{
		unsigned seed = time(0);
		srand(seed);
		playerCard1 = (rand() % (maxValue - minValue + 1)) + minValue;
		playerCard2 = (rand() % (maxValue - minValue + 1)) + minValue;
		cout << "Here are your first two cards: " << playerCard1 << "," << playerCard2 << endl;
		total = playerCard1 + playerCard2;
		cout << "The total of these two cards are" << " " << (total) << endl;
		cout << "Would you like another card? (y/n)" << endl;
		cin >> anotherCard;
		if (anotherCard == "n")
		{
			cout << "Would you like to play again (y/n)?" << endl;
			cin >> playAgain;
		}
		if (anotherCard == "y")
		{
			do
			{
				cout << "You said y, so heres another card" << endl;
				playerCard1 = (rand() % (maxValue - minValue + 1)) + minValue;
				cout << "Your new card is " << playerCard1 << endl;
				cout << "Your new total is " << (total += playerCard1) << endl;
				if (total == bust)
				{
					cout << "You have won!" << endl;
					cout << "Would you like to play again? (y/n)" << endl;
					cin >> playAgain;
					anotherCard = "null";
					if (playAgain == "n")
					{
						return 0;
					}
				}
				else if (total < bust)
				{
					cout << "Would you like another card? (y/n)" << endl;
					cin >> anotherCard;
					if (anotherCard == "n")
					{
						cout << "Would you like to play again? (y/n)" << endl;
						cin >> playAgain;
						anotherCard = "null";
						if (playAgain == "n")
						{
							return 0;
						}
					}
				}
				else if (total > bust)
				{
					playerCard1 = 0;
					playerCard2 = 0;
					total = 0;
					cout << "Bust, the dealer wins." << endl;
					cout << "Would you like to play again? (y/n)" << endl;
					cin >> playAgain;
					anotherCard = "null";
					if (playAgain == "n")
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			} while (anotherCard == "y");
		}
	} while (playAgain == "y");
}
/* 
// This is the test for playing two times. 
[dchan89@hills ~]$ ./a.out
Welcome to Blackjack.
You will start with 2 cards with a random value of 1 to 10.
Your goal is to get as close to 21 as possible.
If you go over 21, you bust, and the game is over.
Here are your first two cards: 4,4
The total of these two cards are 8
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 2
Your new total is 10
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 5
Your new total is 15
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 8
Your new total is 23
Bust, the dealer wins.
Would you like to play again? (y/n)
y
Here are your first two cards: 6,4
The total of these two cards are 10
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 7
Your new total is 17
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 7
Your new total is 24
Bust, the dealer wins.
Would you like to play again? (y/n)
n
*/

/*
// This is the test for playing one time. 
[dchan89@hills ~]$ ./a.out
Welcome to Blackjack.
You will start with 2 cards with a random value of 1 to 10.
Your goal is to get as close to 21 as possible.
If you go over 21, you bust, and the game is over.
Here are your first two cards: 8,9
The total of these two cards are 17
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 9
Your new total is 26
Bust, the dealer wins.
Would you like to play again? (y/n)
n
*/

/*
// This is a test for not even playing one round.
[dchan89@hills ~]$ ./a.out
Welcome to Blackjack.
You will start with 2 cards with a random value of 1 to 10.
Your goal is to get as close to 21 as possible.
If you go over 21, you bust, and the game is over.
Here are your first two cards: 5,9
The total of these two cards are 14
Would you like another card? (y/n)
n
Would you like to play again (y/n)?
n

*/

/*
// This is a test for when the player gets a 21. 
[dchan89@hills ~]$ ./a.out
Welcome to Blackjack.
You will start with 2 cards with a random value of 1 to 10.
Your goal is to get as close to 21 as possible.
If you go over 21, you bust, and the game is over.
Here are your first two cards: 6,7
The total of these two cards are 13
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 2
Your new total is 15
Would you like another card? (y/n)
y
You said y, so heres another card
Your new card is 6
Your new total is 21
You have won!
Would you like to play again? (y/n)
n
*/
