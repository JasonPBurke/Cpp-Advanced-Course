#include "stdafx.h"
#include "PhoneNumber.h"
#include<iostream>
#include <array>
using namespace std;


// Overloaded stream insertion operator; cannot be a member function
// if we would like to invoke it with cout << somePhoneNumber
ostream& operator<<(ostream& output, const PhoneNumber& number) {

	output << "Area Code: " << number.areaCode << "\nExchange: "
		<< number.exchange << "\nLine: " << number.line
		//<< "Full Number: " << "(" << number.areaCode << ") " << number.exchange << "-" << number.line 
		<< "\nPhone Number: " << number.phone;

	return output;// enables cout << a << b << c;
}

// Overload stream extracton operator; cannot be a member function
// if we would like to invoke it with cin >> somePhoneNumber;
istream& operator>>(istream& input, PhoneNumber& number) {

	input.getline(number.phone, 15);// THIS IS CORRECTLY STORING THE ARRAY AT <=15 CHARACTERS ENTERED
	
	if (strlen(number.phone) != 14) {//using strlen to get the length/number of chars held in the phone array
		//cout << "You must enter the phone number in the approprate format length: (555) 555-5555\n";
		input.setstate(ios::failbit);		
	}	
	else if (number.phone[0] != '(') {
		//cout << "in '(' if loop" << endl;
		input.setstate(ios::failbit);
	}
	else if (number.phone[4] != ')') {
		//cout << "in ')' if loop" << endl;
		input.setstate(ios::failbit);
	}
	else if (number.phone[5] != ' ') {
		//cout << "in '-' if loop" << endl;
		input.setstate(ios::failbit);
	}
	else if (number.phone[9] != '-') {
		//cout << "in ' ' if loop" << endl;
		input.setstate(ios::failbit);
	}
	else if (number.phone[1] == '0' || number.phone[1] == '1') {
		//cout << "Area code cannot begin with 1 or 0.\n";
		input.setstate(ios::failbit);
	}
	else if (number.phone[6] == '0' || number.phone[6] == '1') {
		//cout << "Exchange cannot begin with 1 or 0.\n";
		input.setstate(ios::failbit);
	}
	// when a good phone number has been entered, populate the other member data variables from 
	// the phone array.
	if (input.fail() == 0) {
		strncpy_s(number.areaCode, number.phone + 1, 3);
		strncpy_s(number.exchange, number.phone + 6, 3);
		strncpy_s(number.line, number.phone + 10, 4);
	}

	return input; // enables cin >> a >> b >> c;
}


// (123) 456-7890