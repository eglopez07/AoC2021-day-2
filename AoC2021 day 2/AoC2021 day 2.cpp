// AoC2021 day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Submarine.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::ifstream is (argv[1], std::ifstream::in);
		Submarine holyDiver;

		if (!is.is_open())
		{
			std::cout << "File could not be opened. Check file or command line arguments.\n";
			return 0;
		}

		for (std::string input; std::getline(is, input);)
		{
			try
			{
				//holyDiver.registerCommandOriginal(input);
				holyDiver.registerCommandNew(input);
			}
			catch (const std::invalid_argument& ia)
			{
				std::cout << "Exception: Invalid argument. Check input: " << ia.what() << "\n";
			}
			catch (const std::out_of_range& oor)
			{
				std::cout << "Exception: Out of range. Check input: " << oor.what() << "\n";
			}
			catch (const std::exception& is)
			{
				std::cout << is.what() << holyDiver.getLineCount() << '\n';
			}
		}
		holyDiver.calculateFinal();

		std::cout << "Final Horizontal Position: " << holyDiver.getHorizontalPos() << '\n'
			<< "Final Depth: " << holyDiver.getDepth() << '\n'
			<< "When we multiply these together, the product is: " << holyDiver.getFinal() << '\n';

	}
	else { std::cout << "No file path specified. Check command line arguments.\n"; }

	return 0;
}