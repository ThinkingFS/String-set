#ifndef StringSet_header
#define StringSet_header

#include "stdlib.h"
#include "stdio.h"
#include <memory>
#include <string>
#include <utility>



using std::unique_ptr;
using std::make_unique;
using std::string;
using std::move;

class StringSet
{
public:
 
    // Default constructor
    // POST: Created an ArrayClass object with an array of size def_size
    // Compiler default suffices (see variable initializations at end of header)
    StringSet() = default;
    
    // Copy constructor: Create a deep copy of its parameter.
    StringSet(const StringSet &);
    
    // Set the value of the next free element
    /*If a string matching the parameter is already in the array, 
    return false and do not change the array. 
    Otherwise: Insert the string parameter at the next available 
    index; if the underlying array is full, 
    double the maximum size attribute, create an array of 
    twice the size of the current array, copy the contents of 
    the old array to the new array, free memory associated 
    with the old array, and assign new array’s address to object’s 
    array pointer, then insert parameter; increment current size 
    and return true.*/
    bool insert(string);
    
    //If no string match, return false
    //otherwise: Replace the matching string with the 
    //last string in the array (if there is one); decrement 
    //current size and return true.
    bool remove(string);

    //If a string matching the parameter is in the array 
    //return the index of that string, otherwise return 
    //StringSet::NOT_FOUND.
    int find(string) const;

    //Return the current size (the number of strings in the array).
    int size() const;

    //Return a StringSet object that contains the union of this 
    //object and the parameter (if the result is the empty set 
    //the returned StringSet object’s current size should 
    //equal zero); in case you were wondering, this method 
    //is called setunion because union is a reserved word.
    StringSet setunion(const StringSet &) const;

    //Return a StringSet object that contains the intersection 
    //of this object and the parameter.
    StringSet intersection(const StringSet &) const;


    //Return a StringSet object that contains the set difference 
    //of this object and the parameter.
    StringSet difference(const StringSet &) const;

    //prevents the compiler from defining a copy assignment 
    //operator for StringSet. Unfortunately, the default 
    //assignment defined by the language will not be correct 
    //for a class like StringSet that assumes it has exclusive 
    //use of a storage referenced by a pointer.
    // Prevent default copy assignment
    StringSet& operator=(const StringSet&) = delete; 
    

    void printStrings(const string& label) const; // Debugging

    static const int NOT_FOUND {-1};

    // The default capacity
    static constexpr int def_capacity {4};
    
private:
    int arrSize {def_capacity};
    int currentSize {0};
    unique_ptr<string[]> arr{make_unique<string[]>(def_capacity)};
};

#endif
