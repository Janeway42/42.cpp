#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook	YellowPages;
	std::string	command;

	std::cout << "Yellow Pages here!" << std::endl;
	std::cout << "Please enter your query." << std::endl;
	while(1)
	{
		std::cout << "$";
		std::getline(std::cin, command);
		if (command.compare("EXIT") == 0)
			break;
		else if (command.compare("ADD") == 0)
			YellowPages.add();
		else if (command.compare("SEARCH") == 0)
			YellowPages.search();
		else
			std::cout << "Invalid Input \n Please input ADD, SEARCH or EXIT to continue." << std::endl;
	}
	return (0);
}