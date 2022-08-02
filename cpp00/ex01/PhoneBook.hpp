#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

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