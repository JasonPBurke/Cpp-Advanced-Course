// Program03.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "OverloadDemo.h"
#include<array>
#include<string>
#include<iostream>
using namespace std;

int main() {

	OverloadDemo demo1;// create an OverloadDemo object called demo1 to be populated by user input
	int slicesOfPie = 8;
	double pi = 3.14159;
	string sandler = " Gilmore";
	OverloadDemo demo2(slicesOfPie, pi, sandler);// Use constructor to populate demo2 object data

	cout << endl << "Enter a whole number, a decimal number, and a string, " << endl
		 << "seperated by spaces (or the enter key) for the first object: ";
	int num1;
	double num2;
	string string1;
	cin >> num1 >> num2 >> string1;
    demo1.setIntOne(num1);
	demo1.setDoubleOne(num2);
	demo1.setStringOne(string1);

	cout << endl << "For object one, you entered " << demo1.getIntOne() << " for the whole number,"
		<< endl << demo1.getDoubleOne() << " for the decimal number, and "
		<< demo1.getStringOne() << " for the string." << endl;
	cout << endl << "The starting values for object two are " << demo2.getIntOne() << " for the whole number,"
		 << endl << demo2.getDoubleOne() << " for the decimal number, and"
		 << demo2.getStringOne() << " for the string." << endl << endl;

	OverloadDemo demo3;// Create an empty object to copy data to from functions
	demo3 = demo1 + demo2; // Use the overloaded operator+ to assign values to demo3
	cout << endl << "~~After assignment 'demo3 = demo1 + demo2', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	demo3 = demo1 - demo2;// Use the overloaded operator-
	cout << endl << "~~After assignment 'demo3 = demo1 - demo2', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	demo3 = demo1 * demo2;// Use the overloaded operator*
	cout << endl << "~~After assignment 'demo3 = demo1 * demo2', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	demo3 = demo1/demo2;// Use the overloaded operator/
	cout << endl << "~~After assignment 'demo3 = demo1 / demo2', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	++demo3;// Demonstrate the overloaded ++operator
	cout << endl << "~~After call '++demo3', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	demo3++;// Demonstrate the overloaded operator++
	cout << endl << "~~After call 'demo3++', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	--demo3;// Demonstrate the overloaded --operator
	cout << endl << "~~After call '--demo3', demo3's data values~~" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl;
	demo3--;// Demonstrate the overloaded operator--
	cout << endl << "~~After call 'demo3--', demo3's data value~~s" << endl << endl;
	cout << "  demo 3's intOne: " << demo3.getIntOne() << endl
		 << "  demo 3's doubleOne: " << demo3.getDoubleOne() << endl
		 << "  demo 3's stringOne: " << demo3.getStringOne() << endl << endl;

	system("PAUSE");
    return 0;
}

