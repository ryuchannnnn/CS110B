// Assignment 5 Graded Participation.cpp
// You have been hired by the SFPD fraud unit to help detect credit card fraud.  
// They have given you a list of 20 stolen credit card numbers, and want you to write a program that can detect if someone is attempting to use one of 
// these credit card numbers at the local Target store.
// Your program should first read in a list of credit card numbers from a file into an array, and ask the user for a credit card number they would like to use.  
// Then, search the array of credit card numbers to see if the credit card number is in the list.
// Danny Chan 
// CS110B 
// 9/23/2020

#include <iostream>
#include <fstream>
using namespace std;

bool linearSearch(const int list[], int numCreditCards, int userInput)
{
	bool isFound = false;
	for (int i = 0; i < numCreditCards; i++)
	{
		if (list[i] == userInput)
		{
			isFound = true;
		}
	}
	return isFound;
}
	
int main()
{
	const int numCreditCards = 20;
	int list[numCreditCards];
	int userInput;
	ifstream inputFile;
	inputFile.open("cards.txt");
	if (!inputFile)
	{
		cout << "Error in file name" << endl;
		exit(1);
	}
	for (int i = 0; i < numCreditCards; i++)
	{
		inputFile >> list[i];
	}
	cout << "Enter a card number: " << endl;
	cin >> userInput;
	if (linearSearch(list,numCreditCards,userInput) == false)
	{
		cout << "Purchase successful!" << endl;
	}
	if (linearSearch(list, numCreditCards, userInput) == true)
	{
		cout << "Card Denied!" << endl;
	}
	inputFile.close();
}


