#pragma once

#include<stdexcept>

class DivideByZeroException : public std::runtime_error {
public:
	// The constructor will specify the customized default error message
	DivideByZeroException()
		: std::runtime_error{"attempted to divide by zero"} {}
};