#include "Submarine.h"

int Submarine::getHorizontalPos() { return *h; }
void Submarine::setHorizontalPos(int x)
{
	*h = x;
	return;
}

int Submarine::getDepth() { return *d; }
void Submarine::setDepth(int x)
{
	*d = x;
	return;
}

int Submarine::getFinal() { return *final; }
void Submarine::calculateFinal()
{
	*final = *h * *d;
	return;
}

int Submarine::getAim() { return *a; }
void Submarine::setAim(int x)
{
	*a = x;
	return;
}

int Submarine::getLineCount() { return *lineCount; }

int Submarine::getUnitFromString(std::string s)
{
	//add 1 to ignore empty space
	std::size_t pos = s.find(" ") + 1;
	if (pos != std::string::npos)
	{
		return std::stoi(s.substr(pos), &sz);
	}
}

int Submarine::multiplyAimByUnit(int x) { return getAim() * x; }

bool Submarine::validateString(std::string s)
{
	if (s.length() >= 9 && s.substr(0, 8) == "forward ") { return true; }
	else if (s.length() >= 6 && s.substr(0, 5) == "down ") { return true; }
	else if (s.length() >= 4 && s.substr(0, 3) == "up ") { return true; }
	return false;
}

// Used to solve part 1
void Submarine::registerCommandOriginal(std::string direction)
{
	(*lineCount)++;

	if (validateString(direction)) 
	{ 
		if (commands.find(direction) == commands.end()) { commands.insert({ direction, getUnitFromString(direction) }); }
		switch (direction[0])
		{
		case 'f':
			setHorizontalPos(getHorizontalPos() + commands.at(direction));
			break;

		case 'd':
			setDepth(getDepth() + commands.at(direction));
			break;

		case 'u':
			setDepth(getDepth() - commands.at(direction));
			break;
		
		default:
			break;
		}
	}
	else { throw ex; }
	return;
}

//Used to solve part 2
void Submarine::registerCommandNew(std::string direction)
{
	(*lineCount)++;

	if (validateString(direction))
	{
		if (commands.find(direction) == commands.end()) { commands.insert({ direction, getUnitFromString(direction) }); }
		switch (direction[0])
		{
		case 'f':
			setHorizontalPos(getHorizontalPos() + commands.at(direction));
			setDepth( getDepth() + multiplyAimByUnit(commands.at(direction)) );
			break;

		case 'd':
			setAim(getAim() + commands.at(direction));
			break;

		case 'u':
			setAim(getAim() - commands.at(direction));
			break;

		default:
			break;
		}
	}
	else { throw ex; }
	return;
}

int Submarine::getCommandUnit(std::string s)
{
	//0 used to indicate mapped value not found.
	return commands.find(s) != commands.end() ? commands[s] : 0;
}
