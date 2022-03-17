#pragma once

#include <string>
#include <unordered_map>

class Submarine
{
public:
	Submarine()
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

	int getUnitFromString (std::string s);
	bool validateString (std::string s);
	void registerCommand (std::string direction); //add key and mapped value to hash table

	int getCommandUnit(std::string s);

private:
	int h = 0;
	int d = 0;
	int final = 0;

	std::string::size_type sz;

	std::unordered_map<std::string, int> commands;
};

