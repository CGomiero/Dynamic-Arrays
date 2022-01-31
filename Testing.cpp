// Author: Clement Gomiero
// DO NOT change anything in this file. Your code must compile and give the
// correct output with this main on the linux machines.
// Do NOT put an endl in operator<<.  This program terminates normally.
//
// Be sure to name your files using lowercase. Windows is not case sensitive,
// but unix/linux is case sensitive.

// This sample main does not do a thorough job of testing.  When testing arrays,
// be sure to test the middle and also all the boundary conditions.  Test
// values on the boundary and outside the boundaries, i.e., too big/small.

#include "intset.h"
#include <iostream>
using namespace std;

void operationTesting();
void testing();
int teacherTest();
void addTest();

int main() {
	testing();
	operationTesting();
	teacherTest();
	addTest();
}

void addTest() {
	IntSet A(300, 400, 100, 1000);
	IntSet B(-5, 10, -54, 200, 50);
	IntSet C;
	IntSet H(200);
	//cin >> C;
	C = H - B + A;
	cout << C << endl;
}
void testing() {
	IntSet A;
	IntSet B(5);
	IntSet C(5, 15);
	IntSet D(5, 15, 30);
	IntSet E(5, 15, 30, 45);
	IntSet F(5, 15, 30, 45, 13);
	IntSet G(F);

	cout << A;
	cout << B;
	cout << C;
	cout << D;
	cout << E << endl;

	cout << "Input values: put -1 to stop" << endl;
	cin >> A;
	cout << "Constructor output: " << A << endl;

	cout << "IsEmpty?: Expected output = True/1 ---- output = " << A.isEmpty() << endl << endl;
	cout << A << endl;
	cout << "Is in set? " << endl;
	A.insert(5);
	A.insert(30);
	A.insert(45);
	A.insert(-55);

	cout << "5 -- Expected output = true/1 --- Output = " << A.isInSet(5) << endl;
	cout << "30 -- Expected output = true/1 --- Output = " << A.isInSet(30) << endl;
	cout << "45 -- Expected output = true/1 --- Output = " << A.isInSet(45) << endl;
	cout << "50 -- Expected output = False/0 --- Output = " << A.isInSet(50) << endl;
	cout << "-1 -- Expected output = False/0 --- Output = " << A.isInSet(-1) << endl;
	cout << "Array: " << A << endl;
	cout << endl << endl;

	cout << "Insert method" << endl;
	cout << "Adding -1 -- Expected output = False/0 --- Output = " << A.insert(-1) << endl;
	cout << "Adding 5 -- Expected output = true/1 --- Output = " << A.insert(5) << endl;
	cout << "Adding 33 -- Expected output = true/1 --- Output = " << A.insert(33) << endl;
	cout << "Adding 50 -- Expected output = true/1 --- Output = " << A.insert(50) << endl;
	cout << "Array: " << A << endl;
	cout << endl << endl;

	cout << "IsEmpty?: Expected output = False/0 ---- output = " << A.isEmpty() << endl << endl;

	cout << "Remove method" << endl;
	cout << "Remove -1 -- Expected output = False/0 --- Output = " << A.remove(-1) << endl;
	cout << "Remove 5 -- Expected output = true/1 --- Output = " << A.remove(5) << endl;
	cout << "Remove 37 -- Expected output = false/0 --- Output = " << A.remove(37) << endl;
	cout << "Remove 50 -- Expected output = true/1 --- Output = " << A.remove(50) << endl;
	cout << "Remove 500 -- Expected output = False/0 --- Output = " << A.remove(500) << endl;
	cout << "Array: " << A << endl;
	cout << endl << endl;
	cout << "Removing the rest of the array" << endl;
	A.remove(13);
	A.remove(15);
	A.remove(30);
	A.remove(33);
	A.remove(45);

	cout << "Is array empty? -- Expected output = true/1 --- Output = " << A.isEmpty() << endl;
	cout << "A " << A << endl;
	cout << "F " << F << endl;
	cout << "A = F" << endl;
	A = F;
	cout << "A " << A << endl;
}
void operationTesting() {
	IntSet A(-5, 5, 15, 10, 25);
	IntSet B(-3, 33, 3, 23, 25);
	IntSet C(0);
	IntSet D(-3, 33, 3, 23, 25);
	IntSet F(-1);
	IntSet G(100, 0);
	IntSet H(-3, 33, 3, 23, 25);
	IntSet I(H);
	IntSet J(100, 200, 0);

	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "C: " << C << endl;
	cout << "D: " << D << endl;
	cout << "F: " << F << endl;
	cout << "G: " << G << endl;
	cout << "H: " << H << endl;
	cout << "I: " << I << endl;
	cout << "J: " << J << endl;
	A = A;
	F = F;

	cout << "A = A" << A << endl;
	cout << "F = F" << F << endl;
	C = B = A = A;
	D = D - A;
	I *= H;
	G *= A - H + J;

	cout << "C = B = A = A --- Expected output = { 5, 10, 15, 25} " << "Output : " << C << endl;
	cout << "D = D - A --- Expected output = { 3, 23, 33} " << "Output : " << D << endl;
	cout << "I *= H --- Expected output = { 3 23 25 33} " << "Output : " << I << endl;
	cout << "G *= A - H + J --- Expected output = { 0 100} " << "Output : " << G << endl;
}
int teacherTest() {
	IntSet A(9), B(15, 3), C(10, 5, 8), D(12, 5, 10, 12, -500), E, X(D), Y;

	// sets A and B acquire desired values
	//A = { 3 7 9 };
	//B = { 3 5 9 12 15 };
	/*cout << "Enter ints for set A:  " << endl;
	cin >> A;
	cout << "Enter ints for set B:  " << endl;
	cin >> B;*/
	// As a shortcut when testing, you can use insert to avoid typing each time
	 A.insert(3);
	 A.insert(7);
	 B.insert(5);
	 B.insert(9);
	 B.insert(12);

	cout << "A = " << A << endl;               // outputs: A = { 3 7 9}
	cout << "B = " << B << endl << endl;       // outputs: B = { 3 5 9 12 15}

	cout << "Compute  C = A + B" << endl;
	C = A + B;                                 // C is replaced by A+B
	cout << "C = " << C << endl << endl;       // outputs: C = { 3 5 7 9 12 15}

	cout << "Ask if  A == C" << endl;
	cout << ((A == C) ? "A == C" : "A is not == C") << endl << endl;

	cout << "Ask if  A != C" << endl;
	cout << ((A != C) ? "A is not == C" : "A == C") << endl << endl;

	cout << "Compute B - A = " << B - A << endl;            // B - A = { 5 12 15}
	cout << "Compute A - B = " << A - B << endl;            // A - B = { 7}
	cout << "Compute  D = (A * B) + D" << endl;
	cout << "Before: D = " << D;                            // D = { 5 10 12}
	D = (A * B) + D;
	cout << "    After: " << "D = " << D << endl << endl;   // D = { 3 5 9 10 12}

	cout << "Test assignment operators" << endl;
	X = C = D = D;
	Y += A *= B;
	cout << "X = " << X << "    Y = " << Y << endl << endl;

	// miscellaneous stuff
	cout << (D.isInSet(0) ? "0 in set" : "0 not in set") << endl;
	cout << (D.isInSet(-1000) ? "-1000 in set" : "-1000 not in set") << endl;
	cout << (A.isEmpty() ? "A empty" : "A not empty") << endl;
	bool success;

	success = D.insert(-20000);           // handle value out of range
	success = D.remove(20000);            // handle value out of range
	success = D.remove(-5000);            // handle value out of range
	success = D.insert(0);                // put 0 in the set
	success = D.insert(20000);

	return 0;
}
