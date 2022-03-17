#pragma once
#include <exception>

class Exceptions: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Exception: Invalid string at line: ";
	}
};

