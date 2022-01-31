// Author: Clement Gomiero
// a IntSet object is an array of boolean holding numbers as true value
#include "intset.h"

//---------------------------------------------------------------------
// Parameters are integers reprenseted as true value in the array 
// Take zero, one, two, three, four, and five. Parameters have to be integers of any value
IntSet::IntSet(int num1, int num2, int num3, int num4, int num5)
{
	size = max(max(max(max(num1, num2), num3), num4), num5) + 1;
	if (size >= 0) {
		set = new bool[size];
		for (int i = 0; i < size; i++) {
			if (i == num1 || i == num2 || i == num3 || i == num4 || i == num5) {
				set[i] = true;
			}
			else {
				set[i] = false;
			}
		}
	}
	else {
		size = 0;
		set = nullptr;
	}
}

//---------------------------------------------------------------------
// Copy constructor that makes a deep copy of another IntSet object
IntSet::IntSet(const IntSet& copy)
{
	if (copy.isEmpty()) {
		size = 0;
		set = nullptr;
	}
	else {
		size = copy.size;
		set = new bool[size];
		for (int i = 0; i < size; i++) {
			set[i] = copy.set[i];
		}
	}
}

//-------------------------------------------------------------------
// Destructor that delete the pointer and check for any memory leaks
IntSet::~IntSet()
{
	delete[] set;
}

//-------------------------------------------------------------------
// operator =
// Overloaded =: create a deep copy of an IntSet object
IntSet& IntSet::operator=(const IntSet& other)
{
	if (*this == other) {
		return *this;
	}
	if (other.isEmpty()) {
		return *this;
	}

	bool* copyPtr = set;
	delete[] copyPtr;

	size = other.size;
	set = new bool[size];

	for (int i = 0; i < size; i++) {
		if (other.set[i] == true) {
			set[i] = true;
		}
		else {
			set[i] = false;
		}
	}
	return *this;
}

//-------------------------------------------------------------------
// operator ==
// Overloaded ==: compare two IntSet objects 
// Return true if the two objects have the same value in the array
bool IntSet::operator==(const IntSet& other)
{
	if (isEmpty() && other.isEmpty()) {
		return true;
	}
	if (isEmpty() && !other.isEmpty()) {
		return false;
	}
	else if (!isEmpty() && other.isEmpty()) {
		return false;
	}

	int maxSize = max(size, other.size);

	for (int i = 0; i < maxSize; i++) {
		if (set[i] != other.set[i]) {
			return false;
		}
	}
	return true;
}

//-------------------------------------------------------------------
// operator !=
// Overloaded !=: compare two IntSet objects 
// Return ture if two objects are not equal
bool IntSet::operator!=(const IntSet& other)
{
	return !(*this == other);
}

//-------------------------------------------------------------------
// operator +
// Overloaded +: combine two IntSet other together
// Result in an IntSet having the value of two IntSet object
IntSet IntSet::operator+(const IntSet& other) const
{
	IntSet combine;

	if (size >= other.size) {
		combine.size = size;
	}
	else {
		combine.size = other.size;
	}
	if (combine.size < 0) {
		return combine;
	}

	combine.set = new bool[combine.size];
	for (int i = 0; i < combine.size; i++) {

		if (i < this->size && set[i] == true) {
			combine.set[i] = true;
		}
		else if (i < other.size && other.set[i] == true) {
			combine.set[i] = true;
		}
		else {
			combine.set[i] = false;
		}
	}
	return combine;
}

//-------------------------------------------------------------------
// operator -
// Overloaded -: find the difference between two IntSet object
// Result is an array with object value that is in the this.array and not in the other
IntSet IntSet::operator-(const IntSet& other) const
{
	IntSet substract;
	substract.size = this->size;
	substract.set = new bool[size];

	if (substract.size < 0) {
		return substract;
	}
	for (int j = 0; j < size; j++) {
		if (j < other.size) {
			if (set[j] == true && other.set[j] == false) {
				substract.set[j] = true;
			}
			else if ((set[j] == true) && (other.set[j] == true)) {
				substract.set[j] = false;
			}
		}
		else if (j > other.size && set[j] == true) {
			substract.set[j] = true;
		}
		else {
			substract.set[j] = false;
		}
	}
	return substract;
}

//-------------------------------------------------------------------
// operator *
// Overloaded *: find elements that are in both IntSet array
// Result return an IntSet array with elements that are common in both sets
IntSet IntSet::operator*(const IntSet& other) const
{
	IntSet intersection;
	int smallestSize;
	if (size <= other.size) {
		smallestSize = size;
	}
	else {
		smallestSize = other.size;
	}
	if (smallestSize < 0) {
		return intersection;
	}

	intersection.size = smallestSize;
	intersection.set = new bool[smallestSize];

	for (int i = 0; i < smallestSize; i++) {
		if (set[i] == true && other.set[i] == true) {
			intersection.set[i] = true;
		}
		else {
			intersection.set[i] = false;
		}

	}
	return intersection;
}

//-------------------------------------------------------------------
// operator +=
// Overloaded +=: combine this object with another one
// Result add the true value from the other array to this.array
IntSet& IntSet::operator+=(const IntSet& other)
{
	IntSet combine;
	combine = *this + other;
	*this = combine;
	return *this;
}

//-------------------------------------------------------------------
// operator -=
// Overloaded -=: substract common objects from this.array
// Result remove common object of two IntSet object from this.array
IntSet& IntSet::operator-=(const IntSet& other)
{
	IntSet difference;
	difference = *this - other;
	*this = difference;
	return *this;
}

//-------------------------------------------------------------------
// operator *=
// Overloaded *=: find the intersection between this object and the other
// Result return this.array with the common true value of the two array
IntSet& IntSet::operator*=(const IntSet& other)
{
	IntSet intersection;
	intersection = other * *this;
	*this = intersection;
	return *this;
}

//-------------------------------------------------------------------
// insert
// Add a value to the array by changing the index/value equal to true
bool IntSet::insert(int val)
{
	if (val < 0) {
		return false;
	}
	if (isEmpty()) {
		size = val + 1;
		set = new bool[size];
		for (int i = 0; i < size; i++) {
			if (val == i) {
				set[i] = true;
			}
			else {
				set[i] = false;
			}
		}
	}
	if (val > size) {             //if the value is bigger than the size of the array then increase the size of the array

		IntSet copy(*this);
		bool* copyPtr = set;
		delete[] copyPtr;
		size = val + 1;
		set = new bool[size];
		for (int i = 0; i < copy.size; i++) {
			set[i] = copy.set[i];
		}
		for (int i = copy.size + 1; i < size; i++) {
			if (val == i) {
				set[i] = true;
			}
			else {
				set[i] = false;
			}
		}
		return true;
	}
	else {
		set[val] = true;
		return true;
	}
}

//-------------------------------------------------------------------
// remove
// Remove a value from the array by changing a true value at the given val by false
bool IntSet::remove(int val)
{
	if (val < 0 || val > size) {
		return false;
	}
	else if (set[val] == true) {
		set[val] = false;
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------------------------------------------
// isEmpty
// Check if an IntSet is empty by checking the size of the array
bool IntSet::isEmpty() const
{
	if (size == 0) {
		return true;
	}
	for (int i = 0; i < size; i++) {
		if (set[i] == true) {
			return false;
		}
	}
	return true;
}

//-------------------------------------------------------------------
// isIntSet
// Find value in the array, return true if the index is true at the given value
bool IntSet::isInSet(int val)
{
	if (val < 0 || val > size || isEmpty()) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (i == val && set[i] == true) {
			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------
// operator <<
// Overloaded <<: output an IntSet object in this format: { ...}
ostream& operator<<(ostream& output, const IntSet& obj)
{
	if (obj.size == 0) {
		output << "{ }";
		return output;
	}
	output << "{";
	for (int i = 0; i < obj.size; i++) {
		if (obj.set[i] == true) {
			output << " " << i;
		}
	}
	output << "}";
	return output;
}

//-------------------------------------------------------------------
// operator >>
// Overloaded >>: take input from users and build the array from it
istream& operator>>(istream& input, IntSet& obj)
{
	int valInput = 0;
	while (valInput != -1) {    //take user input until -1 is inputted
		input >> valInput;
		obj.insert(valInput);
	}
	return input;
}
