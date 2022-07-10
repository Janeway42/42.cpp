#include <iostream>
#include <string.h>
#include "YellowPages.hpp"

PhoneBook::PhoneBook(void)
{
	char command[7];

	std::cout << "Yellow Pages" << std::endl;
	while(1)
	{
		bzero(command, 7);
		std::cout << "$";
		std::cin >> command;
		command[6] = '\0';
		if (strcmp(command, "EXIT") == 0)
			break;
		else if (strcmp(command, "ADD") == 0)
			add();
		else if (strcmp(command, "SEARCH") == 0)
			search();
		else
			std::cout << "Invalid Input" << std::endl;
	}
	return;
}


// ~Phonebook

void	add()
{
	char input[30];

	bzero(input, 30);

	std::cout << "First Name: ";
	std::cin >> input;
	std::cout << "Last Name: ";
	std::cout << "Nickname: ";
	std::cout << "Phone Number: ";
	std::cout << "Darkest Secret: ";
}