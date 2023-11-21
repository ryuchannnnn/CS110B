// Assignment 13 Int Collection.cpp
//Danny Chan
//CS110B
/*
For this assignment you will add a copy constructor, a destructor, and three overloaded operators to the IntCollection class. 
In the design diagram below, the black member functions represent code that has already been implemented.  
You will be implementing the green items.  Each item that you will be adding to the class is described below the diagram.
*/

#include <iostream>
#include "IntCollection.h"
#include <cstring>
using namespace std;

int main()
{
    IntCollection c;
    IntCollection b;
    IntCollection a;
    c.add(45);
    c.add(-210);
    c.add(77);
    c.add(2);
    c.add(-21);
    c.add(42);
    c.add(7);

    a = b = c;
    cout << " " << endl;
    cout << "Outputting a " << endl;
    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a.get(i) << endl;
    }
    cout << " " << endl;
    cout << "Outputting b " << endl;
    for (int i = 0; i < b.getSize(); i++)
    {
        cout << b.get(i) << endl;
    }
    cout << " " << endl;
    cout << "Outputting c " << endl;
    for (int i = 0; i < c.getSize(); i++)
    {
        cout << c.get(i) << endl;
    }
    if (a == b)
    {
        cout << "A and B are the same." << endl;
    }
    else
    {
        cout << "A and B are not the same" << endl;
    }
    if (a == c)
    {
        cout << "A and C are the same." << endl;
    }
    else
    {
        cout << "A and C are not the same" << endl;
    }
    if (b == c)
    {
        cout << "B and C are the same." << endl;
    }
    else
    {
        cout << "B and C are not the same" << endl;
    }
    c << 45 << -210;

    cout << " " << endl;
    cout << "Outputting c after adding 45 and -210" << endl;
    for (int i = 0; i < c.getSize(); i++)
    {
        cout << c.get(i) << endl;
    }
    cout << " " << endl;
    cout << "Comparing c with a and b after adding 45 and -210" << endl;

    if (a == b)
    {
        cout << "A and B are the same." << endl;
    }
    else
    {
        cout << "A and B are not the same" << endl;
    }
    if (a == c)
    {
        cout << "A and C are the same." << endl;
    }
    else
    {
        cout << "A and C are not the same" << endl;
    }
    if (b == c)
    {
        cout << "B and C are the same." << endl;
    }
    else
    {
        cout << "B and C are not the same" << endl;
    }
    cout << " " << endl;
}

/*6.  addCapacity.  Note that addCapacity() is a private member function.  What happens if you try to call it from outside the class, i.e. by adding the line below to main()?*/
/*
Answer here:
When you try to declare addCapacity, since it is a private member function, you are unable to access it and causes an exit status 1.
main.cpp:85:5: error: 'addCapacity' is a private member of 'IntCollection'
  c.addCapacity();
    ^
./IntCollection.h:18:10: note: declared private here
    void addCapacity();
         ^
1 error generated.
compiler exit status 1
*/


/*
[dchan89@hills ~]$ g++ -c  IntCollection.cpp IntCollection.h
[dchan89@hills ~]$ g++ Assignment13IntCollection.cpp IntCollection.o
[dchan89@hills ~]$ ./a.out
In the constructor
In the constructor
In the constructor

Outputting a
45
-210
77
2
-21
42
7

Outputting b
45
-210
77
2
-21
42
7

Outputting c
45
-210
77
2
-21
42
7
A and B are the same.
A and C are the same.
B and C are the same.

Outputting c after adding 45 and -210
45
-210
77
2
-21
42
7
45
-210

Comparing c with a and b after adding 45 and -210
A and B are the same.
A and C are not the same
B and C are not the same

In the destructor
In the destructor
In the destructor
[dchan89@hills ~]$
*/

