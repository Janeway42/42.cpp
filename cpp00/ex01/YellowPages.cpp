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
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			add(&YellowPages);
		else if (command == "SEARCH")
			search(&YellowPages);
		else
			std::cout << "Invalid Input" << std::endl;
	}
	return (0);
}