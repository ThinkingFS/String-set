StringSet class
Class description
Your class should be named StringSet and should support these operations:

Create an empty set
Copy a set
Insert a string to the set
Remove a string from the set
Test whether a string is in the set
Get the size of the set
Return the set union of the set and another StringSet
Return the intersection of the set and another StringSet
Return the set difference of the set and another StringSet
See the methods section for the method declarations.

Class attributes
Your class should be implemented using a dynamic array and should have the following private member variables, with the specified default initializations:

A unique owning pointer to a string array (unique_ptr<string[]>), pointing to a dynamically-allocated array of strings. By default, it is initialized to an array of four empty strings.
An int that records the current size of the array (i.e., the number of strings stored in the array). By default, it is initialized to 0 (the array is empty).
An int that records the maximum size of the array. By default, it is initialized to the capacity of the default array, four.
Your class should feature the following public constants:

An int value, NOT_FOUND, whose value is -1.
See the ArrayClass.h header file from Lab 1 for example code of default initialization and defining a public constant for a class.

Class files
Your class should consist of a header file StringSet.h that contains the class definition and an implementation file StringSet.cpp that contains the method definitions.

StringSet Methods
Implement each of the public methods described below. In each case you are given the method header which specifies the method’s name, return type and parameter list. A brief description follows each method. You may implement other private methods that you deem necessary.

Implement the methods one at a time, using the recommended sequence.

The class definition in your header file should be exactly as specified here. Do not

Add parameters, delete parameters, or change the type of a specified parameter of a public function
Change the type of a specified public member function or variable
You are allowed to add the following kinds of new members:

Public member functions that you can use in debugging, such as printString()
Private member functions that are called by the public member functions. For example, a member function that performs a computation needed by two public member functions.
Private member variables that are needed for internal computations.
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
Optional debugging method
As you test your function, you may want to facilitate your debugging by displaying the values in a StringSet. You are welcome to define a member function printString:

void printStrings(const string& label) const; // Debugging
When called, this function first prints label, then prints all the strings in the set in any order and format that you choose. The label argument allows you to identify each call out of a series of calls. For example:

auto ss = StringSet();
ss.printStrings("initial empty set");

auto r = ss.insert("hello");
ss.printStrings("after hello");

r = ss.insert("goodbye");
ss.printStrings("after goodbye");
We will not look at or call this function and you do not have to write it. Whether your write it or not, make sure that no output is printed by the code you finally submit to CourSys.

Private methods
You are welcome to define as many or as few private methods as you like. If you find some repeated code in two or more public methods, you could move it into a private method called by the public methods.

Note that if you want to pass a pointer to your private method, it should be a non-owning pointer (say, string*), rather than an owning pointer (say, unique_ptr<string[]>). As mentioned in class, you obtain a non-owning reference to the object owned by a unique_ptr<> via the unique_ptr<>::get() function.

Notes
Dynamic arrays
A dynamic array is an array that increases in size when necessary:

An array of some initial size is created and a unique owning pointer is initialized with its address.
When the array becomes full a new, larger, array is created in dynamic memory.
The contents of the old array are copied to the new array.
The address of the new array is assigned to the array pointer. Because the array pointer is an owning pointer, this automatically deletes the old array. Recall that when you want to assign one unique_ptr<> to another, the right-hand side value has to be wrapped in std::move() (defined in #include <utility>) and the right-hand value is set to nullptr:

using std::make_unique;
using std::move;

auto pa = make_unique<string[]>(10);
auto pb = make_unique<string[]>(50);
pa = move(pa); // Corrected below
pa = move(pb);  // Destroys original value pointed to by pa; sets pb == nullptr
For an example of how to create and declare unique owning pointers to an array, see the second section of Lab 2.
String objects
Your array should contain standard string objects. Your header file should define the standard string class via #include <string>. The string class is defined in the standard namespace (std), so you will probably want to introduce a local instance of the name via a using-declaraction: using std::string;.

For this assignment, the main things you need to know about standard strings are:

You can assign an existing string variable or a string literal to a string variable
Examples: str1 = str2; or str1 = “bob”; (where str1 and str2 are strings)
You can use the normal comparison operators to compare strings
Example: if (str1 < “def”) cout << str1 << “ comes before def in a dictionary”; (where str1 is a string)
You do not need to know anything about the underlying representation of strings; in fact, the two operations described above are pretty much all you need to do with strings in this assignment. The set operations should all be acting on strings, not on the characters that make up those strings—as shown in the examples below.
Cppreference.com provides a complete reference for the standard string classes.

Set operations
The set operations referred to above should be familiar from MACM 101. Recall that:

A set cannot contain duplicate values
The union of two sets R ∪ S is the set of values that appear in either R or S (or in both). Examples:
{1,3,4,5} ∪ {2,3,4} = {1,2,3,4,5}
{cat, bat, rat, badger} ∪ {elephant, bat, hamster} = {cat, bat, rat, badger, elephant, hamster}
The intersection of two sets R ∩ S is the set of values that are common to both R and S. Examples:
{1,3,4,5} ∩ {2,3,4} = {3,4}
{cat, bat, rat, badger} ∩ {elephant, bat, hamster} = {bat}
The set difference of two sets R – S is the set of values that appear in R but not in S. Examples:
{1,3,4,5} – {2,3,4} = {1,5}
{cat, bat, rat, badger} – {elephant, bat, hamster }= {cat, rat, badger}
Main function
You should write a main function in a separate file from your StringSet class; you should use your main function (and other test functions) to test your class methods. You should not submit the file containing the main function to CourSys.

Implementing the methods in sequence, one at a time
I strongly suggest implementing the methods of StringSet one at a time, in the following sequence. After you complete each method, run some test cases. Do not move on to code the next method until you’ve got your current method working correctly.

Some methods, such as insert and the copy constructor StringSet(const StringSet&), have multiple cases, some of which require careful manipulation of the data structures. The recommended sequence asks you to implement them in stages, starting with the basic case (for example, inserting a string that is not already in the array and when the array has available space), testing it, implementing other methods, and then returning to handle the harder cases in the method.

When you revisit a function, as for example when you extend insert to make it expand the array when it is too small, you will actually have to remove or change some of your earlier code. Don’t fight this. It is what you should be doing. As a programmer, you are working as much to produce your own understanding of what the code should do as you are working to produce code. The old code that you remove got your understanding where it needs to be to write the new, more complete code.

This incremental approach is not some simplified “training wheels” that is only used in universities. In fact, it is a simple version of test-driven development, a method used by many professional developers.

The sequence for implementing the methods:

Write StringSet.h. Create a file StringSet.cpp that has a stub version of every method for StringSet. A stub is simply a method that does the barest minimum to meet its calling obligations. It takes the full calling sequence and

If the method does not return a value (its return type is void), it has an empty body.
If the method returns a value of some type, returns the simplest form of that value. For example, the stub for intersection would look like:

StringSet StringSet::intersection(const StringSet &) const
{
    auto result = StringSet{};
    return result; // Return empty StringSet
}
Get this file to compile. That will demonstrate that the method declarations in the .h file match the method definitions in the .cpp file.

Now start to implement the methods in StringSet.cpp.

Simplified insert: Insert a string under the assumption that it is not already in the array and that there is room to store it. This allows you to focus on the basic data structure, without worrying about checking whether the string is already in the array or about expanding the array size. This version should always return true (why?). Test this method with examples that never insert the same string twice and never insert more strings than will fit in the default size.
size: A simple method that requires you to look up a field in the class.
find: Search for a string. You can assume that there is only one copy of a string in the array—that will be enforced by the final version of insert, even though your current version does not enforce this.
remove: Remove a string, if it is in the array. This will give you experience updating values that are already in the array. Look for opportunities to reuse code from find.
StringSet(const StringSet&): This will require you to make a copy of the elements of the array.
Full insert: This comprises two extensions:
Modify your original insert to check that its parameter is not already in the array.
If the current array is at capacity, replace it with a larger array.
These changes require that you do detailed manipulation of the data structure. Once again, look for opportunities to reuse code from find and also from the copy constructor.

You will have to use std::move() in this routine.

setunion: You can implement this method using calls to StringSet(const StringSet&), insert, and some custom code.
intersection: You can implement this method using calls to StringSet(), insert, and some custom code.
difference: You can implement this method using calls to StringSet(), insert, and some custom code.