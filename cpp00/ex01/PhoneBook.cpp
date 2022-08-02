#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

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
	int	i;
	int	nr;
	std::string	temp;

	std::cout << "--------------Yellow-----Pages---------------" <<std::endl;
	std::cout << "|----------|---------------------|----------|" <<std::endl;
	std::cout << "|-----Index|-FirstName|--LastName|--Nickname|" <<std::endl;
	std::cout << "|----------|----------|----------|----------|" <<std::endl;
	
	for (i = 1; i < 9; i++)
		Contacts[i - 1].printRow(i);

	std::cout << "---------------------------------------------" <<std::endl;
	
	std::cout << "Specify contact index to preview all details: " << std::endl;
	while (true)
	{
		try	
		{
			std::getline(std::cin, temp);
			nr = stoi(temp);
			break;
			
		}
		catch(const std::exception e) // catch(const std::exception& e)
		{
			std::cout << "Specify contact index to preview all details: " << std::endl;
		}
	}
	Contacts[nr - 1].printContact();
}