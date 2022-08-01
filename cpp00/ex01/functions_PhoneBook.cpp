#include <iostream>
#include <string.h>
#include "YellowPages.hpp"

PhoneBook:: PhoneBook(void)
{
	index = 0;
	std::cout << "Initializing Yellow Pages\n";
	return;
}

PhoneBook::	~PhoneBook(void)
{
	std::cout << "Yellow Pages out!\n";
	return;
}

void	PhoneBook::add(void)
{
	Contacts[index].writeContact();
	index++;
	if (index == 8)
		index = 0;
}

void PhoneBook::search(void)
{
	int	i = 1;
	std::string	temp;

	std::cout << "|-------------Yellow-----Pages--------------|" <<std::endl;
	std::cout << "|----------|---------------------|----------|" <<std::endl;
	std::cout << "|--Index---|-FirstName|-LastName-|-Nickname-|" <<std::endl;
	std::cout << "|----------|----------|----------|----------|" <<std::endl;
	
	while (i < 9)
	{
		Contacts[i - 1].printRow(i);
		i++;
	}
	std::cout << "|-------------------------------------------|" <<std::endl;
	
	std::cout << "Specify contact to preview all details: " << std::endl;
	std::getline(std::cin, temp);
	Contacts[stoi(temp) - 1].printContact();
}