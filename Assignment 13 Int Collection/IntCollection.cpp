// IntCollection class implementation

#include "IntCollection.h"
#include "IntCollection.h"
#include <cstring>
#include <iostream>
using namespace std;

// constructor
IntCollection::IntCollection()
{
    //initialize member data to reflect an empty IntCollection
    cout << "In the constructor" << endl;
    size = capacity = 0;
    data = NULL;
}

// copy constructor
/*
The copy constructor should perform a deep copy of the argument object, i.e. it should construct an IntCollection with the same size and capacity as the argument, with its own complete copy of the argument's data array.
*/
IntCollection::IntCollection(const IntCollection& c)
{
    data = new int[c.capacity];
    for (int i = 0; i < c.size; i++)
    {
        data[i] = c.data[i];
    }
}

// destructor
/*
Function add() calls addCapacity() to allocate memory when it needs more room.  Nowhere in this program is the memory deallocated with delete [], which means we have a memory leak!  Add a destructor which correctly handles this.
*/
IntCollection::~IntCollection()
{
    cout << "In the destructor" << endl;
    delete[] data;
    data = NULL;
}

void IntCollection::addCapacity()
{
    //create a new, bigger buffer, copy the current data to it, delete 
    //the old buffer, and point our data pointer to the new buffer
    //
    //note: there is a more efficient way to do this using the C 
    //memory management function realloc(), but that is beyond the 
    //scope of our course
    int* newData;
    capacity += CHUNK_SIZE;
    newData = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void IntCollection::add(int value)
{
    //first, allocate more memory if we need to
    if (size == capacity)
    {
        addCapacity();
    }
    //now, add the data to our array and increment size
    data[size++] = value;
}

int IntCollection::get(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "ERROR: get() trying to access index out of range.\n";
        exit(1);
    }
    return data[index];
}

int IntCollection::getSize()
{
    return size;
}

/*
The assignment operator should also perform a deep copy of the argument object.  It must return itself (or more efficiently, a reference to itself) in order to support multiple assignments on the same line, e.g. a = b = c.  If you implement your assignment operator first it could be used in the copy constructor, but this is not a requirement.
*/
IntCollection& IntCollection::operator=(const IntCollection& c)
{
    // a little similar to copy constructor
    size = c.size;
    capacity = c.capacity;
    data = new int[c.capacity];
    for (int i = 0; i < c.size; i++)
    {
        data[i] = c.data[i];
    }
    return *this;
    delete[] data;
}

/*
The "is equals" operator should return true if the argument object has the same size as the receiving object, and the values in both objects’ data arrays are identical.
*/
bool IntCollection::operator==(const IntCollection& c)
{
    if (size != c.size) //checking if size is similar 
    {
        return false;
    }
    for (int i = 0; i < size; i++) //checking if all the numbers are the same
    {
        if (data[i] != c.data[i])
        {
            return false;
        }
    }
    return true;
}

/*
The insertion operator should add the int parameter into the receiving IntCollection.  The functionality is the same as the add() function, i.e. add ints to the collection.  Note, however, that this function must return a reference to itself in order to support multiple insertions on the same line, e.g. c << 45 << -210.  Unlike the assignment operator, this return must be done by reference, because each insertion actually modifies the IntCollection object, and insertion is done from left to right.
*/
IntCollection& IntCollection::operator<<(int value)
{
    if (size == capacity)
    {
        addCapacity();
    }
    data[size++] = value;
    return *this; //pass by reference
}