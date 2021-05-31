#pragma once

#include <iostream>
#include <exception>

class AmountOfTryExceptions : public std::exception
{
public:
	const char* what() const throw ();
};
