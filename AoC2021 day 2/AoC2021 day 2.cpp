// AoC2021 day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Submarine.h"

int main()
{
	Submarine foo;
	std::string bar = "forward 256";

	try
	{
		foo.registerCommand(bar);
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << "Invalid argument, check input: " << ia.what() << "\n";
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Exception: Out of range. Check input: " << oor.what() << "\n";

	}

	std::cout << "Submarine command is as follows: " << bar << "\n"
		<< "Units travelled: " << foo.getCommandUnit(bar) << "\n";

	return 0;
}