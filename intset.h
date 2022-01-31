// Author: Clement Gomiero
// a IntSet object is an array of boolean holding numbers as true value

#ifndef INTSET_H_
#define INTSET_H_
#include <string>
#include <array>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------
// Int Set: Defined as a bool array where each integer present in the set are shown at the 
// index in the array by having the value true. 
//
// Implementation and Assumptions: 
//	-- Integers are stored as true value at the index in the array
//	-- Only positive numbers can be added to the array
//	-- New memory is allocated when the array value is increasing and decreasing when the max value is deleted
//	-- The destructor delete everything for no memory leak

class IntSet
{
public:

	// constructor: used as a default and take up to five arguments 
	IntSet(int num1 = -1, int num2 = -1, int num3 = -1, int num4 = -1, int num5 = -1);

	// copy constructor: make a deep copy of an IntSet object
	IntSet(const IntSet& copy);

	// destructor
	~IntSet();

	// boolean comparison operators
	bool operator ==(const IntSet& other);			//compare size, and values in array
	bool operator !=(const IntSet& other);			//return opposite of the == operator

	// arithmetic operators
	IntSet operator +(const IntSet& other) const;	// add two IntSet object together
	IntSet operator -(const IntSet& other) const;	// return the difference of two IntSet object
	IntSet operator *(const IntSet& other) const;	// return the intersection of two IntSet object

	//assignment operators
	IntSet& operator = (const IntSet& other);		// make a deep copy of another IntSet object
	IntSet& operator +=(const IntSet& other);		// current object += parameter
	IntSet& operator -=(const IntSet& other);		// current object -= parameter
	IntSet& operator *=(const IntSet& other);		// current object *= parameter

	// methods
	bool insert(int val);							// insert the parameter value to the array
	bool remove(int val);							// remove the parameter value from the array
	bool isEmpty() const;							// is the array empty?
	bool isInSet(int val);							// search if the value is in the array

	// input / output
	friend ostream& operator<<(ostream& output, const IntSet& obj);
	friend istream& operator>>(istream& input, IntSet& obj);

private:
	bool* set;										//create a pointer for an array
	int size;										//size of the array
};
#endif