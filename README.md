Public methods

StringSet(const StringSet &)
	This method is a copy constructor, which creates a deep copy of its parameter.

bool insert(string)
	If the parameter "string" matches with a parameter in the array, the method should return false and do not modify the array.
	Otherwise, the method should insert the parameter "string" at the next available index. If the underlying array is full, the method should do the folliwing: 
	1) double the maximum size attribute
	2) create an array of twice the size of the current array
	3) copy the contents of the old array to the new array
	4) free memory associated with the old array
	5) assign new array’s address to object’s array pointer
	6) insert parameter
	7) increment current size and return true.

bool remove(string)
	If no string matches with the parameter in the array, return false .
	Otherwise, replace the matching string with the last string in the array (if there is one), then decrement current size and return true.

int find(string) const
	If the parameter "string" matches with a parameter in the array, return the index of that parameter from the array.
	Otherwise, return StringSet::NOT_FOUND.

int size() const
	Return the current size of the array (the number of strings in the array).

StringSet setunion(const StringSet &) const
	Return a StringSet object that contains the union of this object and the parameter.
	If the result is an empty set, the returned StringSet object’s current size should be zero).
	In case you were wondering, this method is called setunion because union is a reserved word.

StringSet intersection(const StringSet &) const
	Return a StringSet object that contains the intersection of this object and the parameter.

StringSet difference(const StringSet &) const
	Return a StringSet object that contains the set difference of this object and the parameter.

StringSet& operator=(const StringSet&) = delete; // Prevent default copy assignment
	Include this statement in the class definition in StringSet.h. It does not matter whether the statement is in the public or private sections. It prevents the compiler from defining a copy assignment operator for StringSet. Unfortunately, the default assignment defined by the language will not be correct for a class like StringSet that assumes it has exclusive use of a storage referenced by a pointer.

StringSet() = default; // Request default constructor
	Include this statement in the public section of the class definition in StringSet.h. This statement requests that the compiler create a default constructor for this class. Specifying = default is the opposite of specifying = delete: The first requests a default, while the second prohibits it.
	Note: If you have already written a default constructor, simply comment it out in both the .h and .cpp files and add this line to the .h.

Two methods that you do not need to write because the compiler will create them for you:

StringSet()
	This is a default constructor. Since default member initializers will be specified, the compiler will write a default constructor that initializes every member to its default, but note that a default constructor line (see above) has to be added.

~StringSet()
	This is a default destructor. Since the dynamically-allocated array is referred to by a unique owning pointer, the array will be deleted when the pointer is destroyed. The pointer is destroyed in the default destructor for StringSet that the compiler creates for you. If you had instead used a raw pointer such as StringSet*, you would have had to write your own destructor—the compiler-written one would not delete the array.