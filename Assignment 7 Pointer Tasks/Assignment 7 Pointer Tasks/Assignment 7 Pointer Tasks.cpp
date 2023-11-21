// Assignment 7 Pointer Tasks.cpp
// Danny Chan
// CS110B
// 10/11/2020
/*
This part of the assignment will give you a chance to perform some simple tasks with pointers.
The instructions below are a sequence of tasks that are only loosely related to each other.
Start the assignment by creating a file named pointerTasks.cpp with an empty main function, 
then add statements in main() to accomplish each of the tasks listed below.
Some of the tasks will only require a single C++ statement, others will require more than one.
For each step, include a comment in your program indicating which step you are completing in the following statement(s).
The easiest way to do this is copy and paste the below into your main function first, and then fill in your statements.
*/


#include <iostream>
using namespace std;

// 11.
void noNegatives(int* x);

// 21.
void swap(int* x, int* y);

int main()
{
    // 1. Create two variables named int x and y. 

    int x;
    int y;

    // 9. Create two new variables: an int named temp, and an int pointer named p2.

    int temp;
    int* p2;

    // 2. Create an int pointer named p1.

    int* p1;

    // 3. Store the address of x in p1. 

    p1 = &x;

    // 4. Use p1 to use the value of x to 99. 

    *p1 = 99;

    // 5. Using cout and x, display the value of x.

    cout << x << endl;

    // 6. Using cout and the pointer p1, display the value of x.

    cout << *p1 << endl;

    // 7. Store the address of y into p1.

    p1 = &y;

    // 8. Use p1 to set the value of y to -300.

    *p1 = -300;

    // 10. Use temp, p1, and p2 to swap the values in x and y. (this will take a few statements)

    p2 = &x;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // 12. Call the function twice: once with the address of x as the argument, and once with the address of y.

    noNegatives(&x);
    noNegatives(&y);

    // 13. Use p2 to display the values in x and y. (this will require both assignment statements and cout statements)

    p2 = &x;
    cout << "The value in x is: " << *p2 << endl;
    p2 = &y;
    cout << "The value in y is: " << *p2 << endl;

    // 14. Create an int array with two elements. 
    // The array should be named ‘a’.

    int a[2];

    // 15. Use p2 to initialize the first element of a with the value of x.

    a[0] = x;

    // 16. Use p2 to initialize the second element of a with the value of y.

    a[1] = y;

    // 17. Using cout, display the address of the first element in a.

    cout << &a[0] << endl;

    // 18. Using cout, display the address of the second element in a.

    cout << &a[1] << endl;

    // 19. Use p1, p2, and temp to swap the values in the two elements of array ‘a’. 
    // (first point p1 at a[0], then point p2 at a[1]. 
    // After this the swapping steps should look very similar to step 10.)

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;

    // 20. Display the values of the two elements. (The first element should be 99, the second 0).

    cout << a[0] << " This should be 99 " << endl;
    cout << a[1] << " This should be 0 " << endl;

    // 22. Call your swap function with the addresses of x and y, then print their values. (x should be 99, y should be 0).
    swap(&x, &y);
    cout << x << " This should be 99 " << endl;
    cout << y << " This should be 0 " << endl;

    // 23. Call your swap function with the address of the two elements in array ‘a’, then print their values. (a[0] should be 0, a[1] should be 99)
    swap(&a[0], &a[1]);
    cout << a[0] << " This should be 0 " << endl;
    cout << a[1] << " This should be 99 " << endl;
}

// 11. Write a function with the following signature: void noNegatives(int *x). 
// The function should accept the address of an int variable. 
// If the value of this integer is negative then it should set it to zero

void noNegatives(int* x)
{
    if (*x < 0)
    {
        *x = 0;
    }
}

// 21. Write a function named ‘swap’ that accepts two integer pointers as arguments, and then swaps the two integers that the pointers point to.  
// This function must be pass by pointer, i.e. int *, not pass by reference, i.e. int &.

void swap(int* x, int* y)
{
    int tempV2;
    tempV2 = *x;
    *x = *y;
    *y = tempV2;
}

/*[dchan89@hills ~]$ ./a.out
99
99
The value in x is: 0
The value in y is: 99
0x7ffd0b3c151c
0x7ffd0b3c1520
99 This should be 99
0 This should be 0
99 This should be 99
0 This should be 0
0 This should be 0
99 This should be 99
*/