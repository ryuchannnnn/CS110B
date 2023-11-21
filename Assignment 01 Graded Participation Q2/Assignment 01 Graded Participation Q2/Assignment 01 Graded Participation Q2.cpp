// Assignment 01 Graded Participation Q2.cpp 
// Output a statement to ask the user to input the score for the home team today, and store the user's response in a variable homeScore of type int
// Output a statement to ask the user to input the score for the visitor team today, and store the user's response in a variable visitorScore of type int
// Display the scores, and tell the user who won the game
// Also, tell the user if any of the following happened:
// One of the teams had a low score (<3)
// Both of the teams had a low score
// Use a const int for a low score instead of the magic number of 3

#include <iostream>
using namespace std;

int main()
{
    // create variables to store home team's score and visitor team's score
    int homeScore, visitorScore;

    // ask user to input scores for both team
    cout << "Please input the score for the home team today: ";
    cin >> homeScore;
    cout << "Please input the score for the visitor team today: ";
    cin >> visitorScore;

    // display the score of the day
    cout << "Score of Today:" << endl;
    cout << "Home team: " << homeScore << endl;
    cout << "Visitor team: " << visitorScore << endl;

    // tell the user who won the game
    if (homeScore == visitorScore) {
        cout << "It's a tie game." << endl;
    }
    else if (homeScore > visitorScore) {
        cout << "Home team won!" << endl;
    }
    else {
        cout << "Visitor team won!" << endl;
    }

    // create a variable to store low score
    int lowScore = 3;

    // tell the user if any team get a low score
    if (homeScore < lowScore && visitorScore < lowScore) {
        cout << "Both of the teams had a low score." << endl;
    }
    else if (homeScore < lowScore) {
        cout << "Home team had a low score." << endl;
    }
    else if (visitorScore < lowScore) {
        cout << "Visitor team had a low score." << endl;
    }

    return 0;
}
