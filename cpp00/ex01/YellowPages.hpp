#ifndef YELLOWPAGES_HPP
#define YELLOWPAGES_HPP

#include <iostream>
#include <string>

class Contact
{
public:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;
};

class PhoneBook
{
public:
	int		size;
	int		index;
	Contact	Contacts[8];
};

void	add(PhoneBook *book);
void	search(PhoneBook *book);

#endif