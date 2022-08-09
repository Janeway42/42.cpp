#include "Harl.hpp"
#include <iostream>

Harl:: Harl(void)
{
	return;
}

Harl:: ~Harl(void)
{
	return;
}

void Harl::complain(std::string level)
{
	std::string levelsArray[4] = {"DEBUGG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
		if (level == levelsArray[i])
			(this->*functions[i])();
}

void Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << DEBUG << std::endl;
	std::cout << std::endl;
	Harl::_info();
	std::cout << std::endl;
	Harl::_warning();
	std::cout << std::endl;
	Harl::_error();
}

void Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << INFO << std::endl;
	std::cout << std::endl;
	Harl::_warning();
	std::cout << std::endl;
	Harl::_error();
}

void Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << WARNING << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Harl::_error();
}
	
void Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << ERROR << std::endl;
	std::cout << std::endl;
}
