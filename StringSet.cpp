#include "StringSet.h"
#include "stdlib.h"
#include "stdio.h"
#include <memory>
#include <utility>
#include <string>
#include <iostream>


using std::unique_ptr;
using std::make_unique;
using std::string;
using std::move;
using std::cout;
using std::endl;

    
    // Copy constructor: Create a deep copy of its parameter.
    StringSet::StringSet(const StringSet &cp)
    : arrSize{arrSize}, arr{make_unique<string[]>(arrSize)}
    {
       for(int i=0;i<cp.currentSize;i++){
            insert(cp.arr[i]);
       }
        
    }
    
    // Set the value of the next free element
    /*If a string matching the parameter is already in the array, 
    return false and do not change the array. 
    Otherwise: Insert the string parameter at the next available 
    index; 
    if the underlying array is full,  double the maximum size 
    attribute, create an array of twice the size of the current array
    , copy the contents of the old array to the new array, 
    free memory associated with the old array, and assign new array’s 
    address to object’s array pointer, then insert parameter; 
    increment current size and return true.*/
    bool StringSet::insert(string x)
    {

        int i = find(x);
        if (i!=-1){
            return false;
        }
        else if (currentSize==arrSize){
            arrSize = arrSize*2;
            auto arr2 = make_unique<string[]>(arrSize);
            for(int i=0;i<currentSize;i++){
                arr2[i]=arr[i];
            }
            arr = move(arr2);
            arr[currentSize] = x;
            currentSize++;
            return true;
        }
        else{
    	arr[currentSize] = x;
    	currentSize++;
    	return true;
        }

    }
    
    //If no string match, return false
    //otherwise: Replace the matching string with the 
    //last string in the array (if there is one); decrement 
    //current size and return true.
    bool StringSet::remove(string x)
    {   
        int i = find(x);
        if (i!=-1){
            arr[i] = arr[currentSize-1];
            currentSize--;
            return true;
        }
        return false;
    	/*for(int i=0;i<currentSize;i++){
    		if(arr[i]==x){
    			arr[i] = arr[currentSize-1];
    			currentSize--;
    			return true;
    		}
    	}
    	return false;*/
    }

    //If a string matching the parameter is in the array 
    //return the index of that string, otherwise return 
    //StringSet::NOT_FOUND.
    int StringSet::find(string x) const
    {
    	for(int i=0;i<currentSize;i++){
    		if(arr[i]==x){
    			return i;
    		}
    	}
    	return StringSet::NOT_FOUND;
    }

    //Return the current size (the number of strings in the array).
    int StringSet::size() const
    {
    	return currentSize;
    }

    //Return a StringSet object that contains the union of this 
    //object and the parameter (if the result is the empty set 
    //the returned StringSet object’s current size should 
    //equal zero); 
    StringSet StringSet::setunion(const StringSet &cp) const
    {
    	

        if(currentSize==0 || cp.currentSize==0){
            auto newarr = StringSet();
            return newarr;
        }

        auto newarr = StringSet(cp);

        int f;
        int tempsize;

        if(currentSize<cp.currentSize){
            tempsize = cp.currentSize;
        }
        else{tempsize = currentSize;}

        for (int i=0; i<tempsize ;i++){
            f = cp.find(arr[i]);
            if(f==-1){
                newarr.insert(arr[i]);
            }
        }

        return newarr;

    }

    //Return a StringSet object that contains the intersection 
    //of this object and the parameter.
    StringSet StringSet::intersection(const StringSet &cp) const
    {
        auto newarr = StringSet();

        if(currentSize==0 || cp.currentSize==0){
            return newarr;
        }

        int f;
        int tempsize;

        if(currentSize<cp.currentSize){
            tempsize = cp.currentSize;
        }
        else{tempsize = currentSize;}

        for (int i=0; i<tempsize ;i++){
            newarr.insert(arr[i]);
        }


        for (int i=0; i<tempsize ;i++){
            f = cp.find(arr[i]);
            if(f==-1){
                newarr.remove(arr[i]);
            }
        }

        return newarr;
    }


    //Return a StringSet object that contains the set difference 
    //of this object and the parameter.
    StringSet StringSet::difference(const StringSet &cp) const
    {  
    	auto newarr = StringSet();

        if(cp.currentSize==0 || currentSize==0){
            return newarr;
        }

        int f;
        int tempsize;

        if(currentSize<cp.currentSize){
            tempsize = cp.currentSize;
        }
        else{tempsize = currentSize;}

        for (int i=0; i<tempsize ;i++){
            newarr.insert(arr[i]);
        }


       for (int i=0; i<tempsize ;i++){
            f = newarr.find(cp.arr[i]);
            if(f!=-1){
                newarr.remove(cp.arr[i]);
            }
        }

        return newarr;
    }

 
    //StringSet& operator=(const StringSet&) = delete; 

	// Debugging
    void StringSet::printStrings(const string& label) const
    {
        cout << label;
    	for (int i=0;i<currentSize;i++){
    		cout << ' ' <<	arr[i] << ' ';
    	}    	
        cout << endl;
    	return;
    } 
