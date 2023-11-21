/*  Assignment 02 Graded Participation Q2.cpp 
    Write a C++ program which tracks assignment grades.  It should do the following:
    Ask the user how many assignments there are.
    Input a grade for each assignment from the user.
    Print out the total points scored, and the average(mean) score.
    If you have time, add these extra features :
    print out the letter grade for the average score using the standard grading formula(90 or higher is an A, 80 or higher is a B, etc.)
    Make sure each grade is at least 0 and at most 100
*/

#include <iostream>
using namespace std;
    int main() 
    {
        int numAssignments;
        float total = 0;
        bool numAssignmentsValid = false;
        while (numAssignmentsValid == false) 
        {
            cout << "How many assignments are there?: ";
            cin >> numAssignments;
            if (numAssignments < 0) {
                cout << "Please enter a valid number of assignments greater than 0." << endl;
                continue;
            }
            numAssignmentsValid = true;
        }

        for (int i = 0; i < numAssignments;) 
        {
            float assignmentScore = 0;
            cout << "What is the score of the current assignment?: ";
            cin >> assignmentScore;

            if (assignmentScore < 0 || assignmentScore > 100) 
            {
                cout << "Please enter a score between 0 and 100" << endl;
                continue;
            }

            total += assignmentScore;

            i++;
        }

        float averageScore = (total / float(numAssignments));
        char letterGrade;

        if (averageScore >= 90) 
        {
            letterGrade = 'A';
        }
        else if (averageScore >= 80 && averageScore <= 89) 
        {
            letterGrade = 'B';
        }
        else if (averageScore >= 70 && averageScore <= 79) 
        {
            letterGrade = 'C';
        }
        else if (averageScore >= 60 && averageScore <= 69) 
        {
            letterGrade = 'D';
        }
        else if (averageScore <= 59) 
        {
            letterGrade = 'F';
        }

        cout << "The total score is " << total << endl;
        cout << "The average score is " << averageScore << endl;
        cout << "Your grade is " << letterGrade << endl;

        return 0;
    }

