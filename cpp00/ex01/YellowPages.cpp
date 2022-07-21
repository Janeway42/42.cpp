# include <iostream>
# include "YellowPages.hpp"

int main(int argc, char **argv)
{
	PhoneBook	YellowPages;
	char		command[7];

	
	YellowPages.index = 1;
	std::cout << "Yellow Pages here!" << std::endl;
	std::cout << "Please enter your query." << std::endl;
	while(1)
	{
		std::cin >> command;
		command[6] = '\0';
		if (strcmp(command, "EXIT") == 0)
			break;
		else if (strcmp(command, "ADD") == 0)
			add(&YellowPages);
		else if (strcmp(command, "SEARCH") == 0)
			search(&YellowPages);
		else
			std::cout << "Invalid Input \n Please input ADD, SEARCH or EXIT to continue." << std::endl;
	}
	return (0);
}