// Assignment 10 Graded Participation Q1.cpp
/*
Implement the Rectangle class as discussed in the videos and pdfs.
Enhance the Rectangle class with two new member functions:
double getPerimeter() - returns the perimeter of the rectangle, i.e. 2*width+2*length
bool isSquare() - returns true if the rectangle is a square, i.e. length is equal to width, returns false if not
Demonstrate your class works with a main function that instantiates a Rectangle object, and shows sample output for these functions working
*/
//

#include <iostream>
#include "Rectangle.h"
using namespace std;
int main()
{
	Rectangle r;
	Rectangle* roomPtr = NULL;
	roomPtr = &r;
	int userWidth, userLength;
	cout << "Enter width: " << endl;
	cin >> userWidth;
	roomPtr->setWidth(userWidth);
	cout << "Enter length: " << endl;
	cin >> userLength;
	roomPtr->setLength(userLength);
	cout << "Your rectangle has area: " << roomPtr->getArea() << " sq ft. " << endl;
	cout << "Your rectangle has perimeter: " << roomPtr->getPerimeter() << " sq ft. " << endl;
	if (roomPtr->isSquare() == true)
	{
		cout << "This is also a square." << endl;
	}
	else
	{
		cout << "This is not a square." << endl;
	}

	return 0;
}


/*
[dchan89@hills ~]$ g++ -c Rectangle.cpp
[dchan89@hills ~]$ ls
a.out                           Assignment7PointerTasks.cpp      PeerReview2.pr
Assignment 0 First Program.cpp  Assignment8C-Strings.cpp         PeerReview2SecondSubmission.pr
Assignment0FirstProgram.cpp     Assignment9TheLeagueStructs.cpp  PeerReview3.pr
Assignment1Ages.cpp             AssignmentTwoBlackjack.cpp       PeerReview3SecondSubmission.pr
Assignment1Comments131B.py      ContainersPt2.py                 PeerReview4.pr
Assignment2.py                  Containers.py                    PeerReview5.pr
Assignment2Senate.py            cs110a                           PeerReview6.pr
Assignment3NumberGuesser.cpp    CS110BMidtermQ1.cpp              PeerReview7.pr
Assignment3Senate.py            hello.cpp                        Rectangle.cpp
Assignment4Dice.py              HelloWorld.cpp.save              Rectangle.h
Assignment4PokerHands.cpp       Loops131B.py                     Rectangle.o
Assignment5TheLeague.cpp        PeerReview1.pr                   RectangleProgramAssign10GradedP.cpp
[dchan89@hills ~]$ g++ RectangleProgramAssign10GradedP.cpp Rectangle.o
[dchan89@hills ~]$ ./a.out
Enter width:
10
Enter length:
10
Your rectangle has area: 100 sq ft.
Your rectangle has perimeter: 40 sq ft.
This is also a square.
[dchan89@hills ~]$ ./a.out
Enter width:
10
Enter length:
14
Your rectangle has area: 140 sq ft.
Your rectangle has perimeter: 48 sq ft.
This is not a square.
[dchan89@hills ~]$
*/