// Assignment 10 Circle Class.cpp:
// Danny Chan
// CS110B
// 10/29/2020
/*
Write a main function that tests your class.  It should instantiate a number of circle objects with different radius values and centers.  You should test all your member functions until you are confident that they work.  At minimum, make sure you try each of the following and provide sample output for each of the below test cases:
Create a local circle object and set its x, y, and radius. Verify that its area is calculated correctly.
Create a circle pointer, and point it at your local circle object.  Use this pointer to set its x, y, and radius values to new values.
Using your pointer, verify that your containsPoint() function works by trying a point which is in fact in your circle, and showing it returns true.
Also, try a different point which is not in your circle and show it returns false.
(using dot notation)
*/

#include <iostream>
#include "Circle.h"
using namespace std;
int main()
{
    Circle c;
    float centerX, centerY, radius, pointX, pointY;
    cout << "Enter center of circle X coordinate: " << endl;
    cin >> centerX;
    c.setX(centerX);
    cout << "Enter center of circle Y coordinate: " << endl;
    cin >> centerY;
    c.setY(centerY);
    cout << "Enter radius of circle: " << endl;
    cin >> radius;
    c.setRadius(radius);
    cout << "The area of your circle is: " << c.getArea() << endl;
    cout << "Let's see if a point you enter is within a circle." << endl;
    cout << "Enter a x coordinate: " << endl;
    cin >> pointX;
    cout << "Enter a y coordinate: " << endl;
    cin >> pointY;
    if (c.containsPoint(pointX, pointY) == true)
    {
        cout << "The point you entered, " << pointX << "," << pointY << " is within the circle." << endl;
    }
    else
    {
        cout << "The point you entered, " << pointX << "," << pointY << " is not in the circle." << endl;
    }
    return 0;
}

/*
(ptr notation)
int main()
{
  Circle c;
  Circle *circlePtr = NULL;
  circlePtr = &c;
  float centerX,centerY,radius,pointX,pointY;
  cout << "Enter center of circle X coordinate: " << endl;
  cin >> centerX;
  circlePtr->setX(centerX);
  cout << "Enter center of circle Y coordinate: " << endl;
  cin >> centerY;
  circlePtr->setY(centerY);
  cout << "Enter radius of circle: " << endl;
  cin >> radius;
  circlePtr->setRadius(radius);
  cout << "The area of your circle is: " << c.getArea() << endl;
  cout << "Let's see if a point you enter is within a circle." << endl;
  cout << "Enter a x coordinate: " << endl;
  cin >> pointX;
  cout << "Enter a y coordinate: " << endl;
  cin >> pointY;
  if(c.containsPoint(pointX,pointY) == true)
  {
    cout << "The point you entered, " << pointX << "," << pointY << " is within the circle." << endl;
  }
  else
  {
    cout << "The point you entered, " << pointX << "," << pointY << " is not in the circle." << endl;
  }
  return 0;
}

*/


/*
[dchan89@hills ~]$ ./a.out
Enter center of circle X coordinate:
2
Enter center of circle Y coordinate:
3
Enter radius of circle:
2
The area of your circle is: 12.56
Let's see if a point you enter is within a circle.
Enter a x coordinate:
2
Enter a y coordinate:
4
The point you entered, 2,4 is within the circle.
[dchan89@hills ~]$ ./a.out
Enter center of circle X coordinate:
2
Enter center of circle Y coordinate:
3
Enter radius of circle:
2
The area of your circle is: 12.56
Let's see if a point you enter is within a circle.
Enter a x coordinate:
2
Enter a y coordinate:
10
The point you entered, 2,10 is not in the circle.
[dchan89@hills ~]$
*/