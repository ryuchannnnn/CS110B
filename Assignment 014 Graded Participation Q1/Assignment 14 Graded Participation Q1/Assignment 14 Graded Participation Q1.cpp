// Assignment 14 Graded Participation Q1.cpp :
// Danny Chan
// CS110B
// 12/6/2020
/*
Implement the GradedActivity class as discussed in the videos.  Copying from the pdfs is fine.
Create a new class Assignment which is derived from GradedActivity.  
It should have three private member ints for 3 different parts of an assignment score: functionality (max 50 points), efficiency (max 25 points), and style (max 25 points).
Create member function set() in Assignment which takes three parameter ints and sets the member variables.  
It should also set its score member, which is inherited from GradedActivity, using the setScore() function, to functionality + efficiency + style.  
Signature: void Assignment::set(int, int, int)
Create a main program which instantiates an Assignment, asks the user for its functionality, efficiency, and style scores, and prints out the score and letter grade for the assignment.
*/

#include <iostream>
using namespace std;

class GradedActivity
{
protected:
    double score;
public:
    GradedActivity()
    {
        score = 0.0;
    }
    GradedActivity(double s)
    {
        score = s;
    }
    void setScore(double s)
    {
        score = s;
    }
    double getScore()
    {
        return score;
    }
    char getLetterGrade() const;
};

class Assignment : public GradedActivity
{
private:
    int functionality, efficiency, style;
public:
    Assignment() : GradedActivity()
    {
        functionality = efficiency = style = 0;
    }
    void set(int, int, int);
};

char GradedActivity::getLetterGrade() const
{
    char letterGrade;
    if (score > 89)
        letterGrade = 'A';
    else if (score > 79)
        letterGrade = 'B';
    else if (score > 69)
        letterGrade = 'C';
    else if (score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    return letterGrade;
}

void Assignment::set(int f, int e, int s)
{
    if (f <= 50)
        functionality = f;
    else
    {
        cout << "Functionality score above 50 is invalid. Try again.";
        exit(1);
    }
    if (e <= 25)
        efficiency = e;
    else
    {
        cout << "Efficiency score above 25 is invalid. Try again.";
        exit(1);
    }
    if (s <= 25)
        style = s;
    else
    {
        cout << "Style score above 25 is invalid. Try again.";
        exit(1);
    }
    score = functionality + efficiency + style;
}


int main()
{
    int num1, num2, num3;
    Assignment scorer;
    cout << "Please enter a score for functionality: ";
    cin >> num1;
    cout << "Please enter a score for efficiency: ";
    cin >> num2;
    cout << "Please enter a score for style: ";
    cin >> num3;
    scorer.set(num1, num2, num3);
    cout << "Score: " << scorer.getScore() << endl;
    cout << "Grade: " << scorer.getLetterGrade() << endl;
}