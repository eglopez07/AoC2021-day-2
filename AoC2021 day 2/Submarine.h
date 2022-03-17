#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include "Exceptions.h"

class Submarine
{
public:
	Submarine() : h(std::make_unique<int>(0)), d(std::make_unique<int>(0)), final(std::make_unique<int>(0)), lineCount(std::make_unique<int>(0))
	{

	}
	~Submarine()
	{

	}

	int getHorizontalPos();
	void setHorizontalPos(int a);

	int getDepth();
	void setDepth(int a);

	int getFinal();
	void calculateFinal();

	int getLineCount();

	int getUnitFromString (std::string s);
	bool validateString (std::string s);
	void registerCommand (std::string direction); //add key and mapped value to hash table

	int getCommandUnit(std::string s);

private:
	std::unique_ptr<int> h, d, final, lineCount;

	std::string::size_type sz;

	std::unordered_map<std::string, int> commands;

	Exceptions ex;
};

