// Assignment 02 Graded Participation.cpp
// Write a C++ program for a baseball game which does the following:
// Ask the user for the score for the home team, then ask the user for the score for the away team. 
// Display the home team and away team scores, and tell the user who won the game. 
// At the end of the program, ask the user if they would like to go again.  
// If the user enters 'y' then run the program again, otherwise it's done.  Let the user run it as many times as desired.
// Danny Chan 
// CS 110B 
// 9/1/2020

#include <iostream>
using namespace std;

int main()
{
    int homeTeamScore, awayTeamScore;
    string goAgain;
    {
        do
        {
            cout << "What is the score for the home team?";
            cin >> homeTeamScore;
            cout << "What is the score for the away team?";
            cin >> awayTeamScore;
            cout << "The home team score is: " << homeTeamScore << endl;
            cout << "The away team score is: " << awayTeamScore << endl;
            if (homeTeamScore > awayTeamScore)
            {
                cout << "The home team won the game." << endl;
            }
            else if (awayTeamScore > homeTeamScore)
            {
                cout << "The away team won the game." << endl;
            }
            else if (awayTeamScore == homeTeamScore)
            {
                cout << "Its a tie." << endl;
            }
            cout << "Go again? (y/n) ";
            cin >> goAgain;
        } while (goAgain == "y");
    }
}