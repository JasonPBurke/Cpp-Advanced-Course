#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include "stdafx.h"
#include <iostream>
#include <string>

class PhoneNumber {

	friend std::ostream& operator<<(std::ostream&, const PhoneNumber&); // Overloaded insertion operator
	friend std::istream& operator>>(std::istream&, PhoneNumber&); // Overloaded extraction operator

private:

	char phone[15]; // Holds entire phone number plus \0
	char areaCode[4]; // Holds area code plus \0
	char exchange[4]; // Holds exchange plus \0
	char line[5]; // Holds line plus \0

};
#endif // PHONENUMBER.H