#include "Submarine.h"

int Submarine::getHorizontalPos() { return h; }
void Submarine::setHorizontalPos(int a)
{
	h = a;
	return;
}

int Submarine::getDepth() { return d; }
void Submarine::setDepth(int a)
{
	d = a;
	return;
}

int Submarine::getFinal() { return final; }
void Submarine::calculateFinal()
{
	final = h * d;
	return;
}

int Submarine::getUnitFromString(std::string s)
{
	//add 1 to ignore empty space
	std::size_t pos = s.find(" ") + 1;
	if (pos != std::string::npos)
	{
		return std::stoi(s.substr(pos), &sz);
	}
}

bool Submarine::validateString(std::string s)
{
	if (s.length() >= 9 && s.substr(0, 8) == "forward ") { return getUnitFromString(s) >= 0; }
	else if (s.length() >= 6 && s.substr(0, 5) == "down ") { return getUnitFromString(s) >= 0; }
	else if (s.length() >= 4 && s.substr(0, 3) == "up ") { return getUnitFromString(s) >= 0; }
	return false;
}

void Submarine::registerCommand(std::string direction)
{
	if (validateString(direction)) { commands.insert({ direction, getUnitFromString(direction) }); }
}

int Submarine::getCommandUnit(std::string s)
{
	return commands[s];
}
