#ifndef YELLOWPAGES_HPP
#define YELLOWPAGES_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_secret;

public:
	Contact(void);
	~Contact(void);

	void	writeContact(void);
	void	printRow(int i);
	void	printContact(void);

};

class PhoneBook
{
private:
	Contact Contacts[8];

public:

	PhoneBook(void);
	~PhoneBook(void);

	int		index;

	void	add(void);
	void	search(void);
};

#endif