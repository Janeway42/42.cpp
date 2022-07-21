#include <iostream>
#include <string.h>
#include "YellowPages.hpp"

void	add(PhoneBook *book)
{
	Contact *list;

	list = &book->Contacts[book->index];
	
	std::cout << "First name: ";
	std::getline (std::cin, list->firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, list->lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, list->nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, list->phoneNumber);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, list->secret);
	book->index++;
	if (book->index == 9)
		book->index = 1;
}

void	printContact(PhoneBook *book, int location)
{
	Contact person;

	person = book->Contacts[location];

	std::cout << "First Name: ", std::cout << person.firstName << std::endl;
	std::cout << "Last Name: ", std::cout << person.lastName << std::endl;
	std::cout << "Nickname: ", std::cout << person.nickname << std::endl;
	std::cout << "Telephone: ", std::cout << person.phoneNumber << std::endl;
	std::cout << "Darkest Secret: ", std::cout << person.secret << std::endl;
}

void search(PhoneBook *book)
{
	int	i = 1;
	std::string	temp;

	while (i <= book->size)
	{
		std::cout << "|----------|--Yellow-----Pages---|----------|" <<std::endl;
		std::cout << "|----------|---------------------|----------|" <<std::endl;
		std::cout << "|--Index---|-FirstName|-LastName-|-Nickname-|" <<std::endl;
		std::cout << "|----------|----------|----------|----------|" <<std::endl;

		std::cout << "|", std::cout << i, std::cout << "|",
			std::cout << book->Contacts[i].firstName, std:: cout << "|",
			std::cout << book->Contacts[i].lastName, std::cout << "|",
			std::cout << book->Contacts[i].nickname, std::cout << "|" << std::endl;

		std::cout << "|----------|----------|----------|----------|" <<std::endl;
		i++;
	}
	std::cout << "Specify contact to preview all details: " << std::endl;
	std::getline(std::cin, temp);
	printContact(book, stoi(temp));
}