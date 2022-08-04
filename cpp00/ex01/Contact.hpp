#ifndef CONTACT_HPP
#define CONTACT_HPP

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

void	printInfo(std::string name);
int		errorEOF(void);

#endif