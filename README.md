Public methods
StringSet(const StringSet &)
Copy constructor: Create a deep copy of its parameter.
bool insert(string)
If a string matching the parameter is already in the array, return false and do not change the array.
Otherwise: Insert the string parameter at the next available index; if the underlying array is full, double the maximum size attribute, create an array of twice the size of the current array, copy the contents of the old array to the new array, free memory associated with the old array, and assign new array’s address to object’s array pointer, then insert parameter; increment current size and return true.

bool remove(string)
If no string matching the parameter is in the array, return false .
Otherwise: Replace the matching string with the last string in the array (if there is one); decrement current size and return true.

int find(string) const
If a string matching the parameter is in the array return the index of that string, otherwise return StringSet::NOT_FOUND.
int size() const
Return the current size (the number of strings in the array).
StringSet setunion(const StringSet &) const
Return a StringSet object that contains the union of this object and the parameter (if the result is the empty set the returned StringSet object’s current size should equal zero); in case you were wondering, this method is called setunion because union is a reserved word.
StringSet intersection(const StringSet &) const
Return a StringSet object that contains the intersection of this object and the parameter.
StringSet difference(const StringSet &) const
Return a StringSet object that contains the set difference of this object and the parameter.
StringSet& operator=(const StringSet&) = delete; // Prevent default copy assignment
Include this statement in the class definition in StringSet.h. It does not matter whether you put it in the public or private sections. It prevents the compiler from defining a copy assignment operator for StringSet. Unfortunately, the default assignment defined by the language will not be correct for a class like StringSet that assumes it has exclusive use of a storage referenced by a pointer.
StringSet() = default; // Request default constructor
Include this statement in the public section of the class definition in StringSet.h. This statement requests that the compiler create a default constructor for this class. Specifying = default is the opposite of specifying = delete: The first requests a default, while the second prohibits it.
Note: If you have already written a default constructor, simply comment it out in both the .h and .cpp files and add this line to the .h.

Two methods that you do not need to write because the compiler will create them for you:

StringSet()
Default constructor. Because you will specify default member initializers, the compiler will write a default constructor that initializes every member to its default.
But note that you have to add a default constructor line (see above).

~StringSet()
Destructor . Because the dynamically-allocated array is referred to by a unique owning pointer, the array will be deleted when the pointer is destroyed. And the pointer is destroyed in the default destructor for StringSet that the compiler creates for you. If you had instead used a raw pointer such as StringSet*, you would have had to write your own destructor—the compiler-written one would not delete the array.