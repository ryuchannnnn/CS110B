// Danny Chan
// CS 110B
// 10/7/2020
// Assignment 7 Graded Participation
/*
The local taqueria has decided they need to raise their prices.  
In order to soften the blow to their customers, they also want to rename all their burritos to make them sound more desirable.
Your program should create two arrays in main() - one string array with 3 burrito types and one float array with 3 associated prices, defined below:
Now, main should declare a string pointer and a float pointer.  
Using the pointers and a for loop, add " Especial" to the end of each element in the names array, and add 2.00 to each element in the prices array.  
Do not use array notation, i.e. names[1], use only pointer notation, i.e. *names or *(names+1) etc.  
Finally, using your pointers and a for loop, print out the new menu.
Hint: it is straightforward to append to a string in C++.  If you have the following string:
You can add " Especial" to the end of it by doing this:
*/
//

#include <iostream>
using namespace std;

int main()
{
    string names[] = {"Carnitas", "Pollo", "Veggie" };
    float prices[] = {6.95, 6.25, 5.95 };
    string* ptr = names;
    float* plusprices = prices;
    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = *(ptr + i) + " " + "Especial" + " ";
        cout << *(ptr + i);
        *(plusprices + i) = *(plusprices + i) + 2.00;
        cout << *(plusprices + i) << endl;
    }
}

