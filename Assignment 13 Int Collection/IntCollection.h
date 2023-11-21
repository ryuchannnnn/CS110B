// IntCollection class header

#ifndef INTCOLLECTION_H
#define INTCOLLECTION_H

const int CHUNK_SIZE = 5;	// allocate memory in chunks of ints of this size

class IntCollection
{
private:
    // the number of ints currently stored in the int collection
    int size;
    // the total number of elements available for stoarge in the data array
    int capacity;
    // a pointer to the dynamically allocated data array
    int* data;
    // a private member function to allocate more memory if necessary          
    void addCapacity();
public:
    // constructor
    IntCollection();
    // destructor							
    ~IntCollection();
    // copy constructor
    IntCollection(const IntCollection& c);
    void add(int value);
    int get(int index);
    int getSize();
    // overloaded = operator
    IntCollection& operator=(const IntCollection& c);
    // overloaded == operator
    bool operator==(const IntCollection& c);
    // overloaded << operator
    IntCollection& operator<<(int value);
};
#endif

