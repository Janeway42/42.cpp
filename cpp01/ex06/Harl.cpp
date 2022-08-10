#include "Harl.hpp"
#include <iostream>

Harl:: Harl(void)
{
}

Harl:: ~Harl(void)
{
}

int Harl::getLevelNumber(std::string level)
{
	int out = 4;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "DEFAULT"};

	for (int i = 0; i < 4; i++)
		if (level.compare(levels[i]) == 0)
			out = i;
	return (out + 1);
}

void Harl::complain(std::string level)
{
	switch (Harl::getLevelNumber(level))
	{
		case 1:
			Harl::_debug();
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 2:
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 3:
			Harl::_warning();
			Harl::_error();
			break;
		case 4:
			Harl::_error();
			break;
		default:
			Harl::_default();
			break;
	}
}

void Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << DEBUG << std::endl;
	std::cout << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << INFO << std::endl;
	std::cout << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << WARNING << std::endl;
	std::cout << std::endl;
}
	
void Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << ERROR << std::endl;
}

void Harl::_default(void)
{
	std::cout << DEFAULT << std::endl;
	std::cout << std::endl;
}
