/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   contact.class.cpp                                 e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/03/24 17:21:02 by dries             *8*   8   *8*          */
/*   Updated: 2021/03/24 17:21:02 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"
#include <cstring>

Contact::Contact(void) {
	_isEmpty = 1;
	_clearField(_firstName);
	_clearField(_lastName);
	_clearField(_nickname);
	_clearField(_login);
	_clearField(_postalAddress);
	_clearField(_emailAddress);
	_clearField(_phoneNumber);
	_clearField(_birthdayDate);
	_clearField(_favoriteMeal);
	_clearField(_underwearColor);
	_clearField(_darkestSecret);
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::writeContact(void) {
	std::cout << "Enter details into the fields as they appear." << std::endl;
	std::cout << "First Name: ";
	std::cin >> this->_firstName;
	std::cout << "Last Name: ";
	std::cin >> this->_lastName;
	std::cout << "Nickname: ";
	std::cin >> this->_nickname;
	std::cout << "Login: ";
	std::cin >> this->_login;
	std::cout << "Postal Address: ";
	std::cin >> this->_postalAddress;
	std::cout << "Email Address: ";
	std::cin >> this->_emailAddress;
	std::cout << "Phone Number: ";
	std::cin >> this->_phoneNumber;
	std::cout << "Birthday Date: ";
	std::cin >> this->_birthdayDate;
	std::cout << "Favorite Meal: ";
	std::cin >> this->_favoriteMeal;
	std::cout << "Underwear Color: ";
	std::cin >> this->_underwearColor;
	std::cout << "Darkest Secret: ";
	std::cin >> this->_darkestSecret;
	this->_isEmpty = 0;
	return;
}

void	Contact::clearContact(void) {
	this->_clearField(this->_firstName);
	this->_clearField(this->_lastName);
	this->_clearField(this->_nickname);
	this->_clearField(this->_login);
	this->_clearField(this->_postalAddress);
	this->_clearField(this->_emailAddress);
	this->_clearField(this->_phoneNumber);
	this->_clearField(this->_birthdayDate);
	this->_clearField(this->_favoriteMeal);
	this->_clearField(this->_underwearColor);
	this->_clearField(this->_darkestSecret);
	this->_isEmpty = 1;
	return;
}

void	Contact::getContact(void) {
	if (this->_isEmpty == 0) {
		std::cout << "First Name:	" << this->_firstName << std::endl;
		std::cout << "Last Name:	" << this->_lastName << std::endl;
		std::cout << "Nickname:	" << this->_nickname << std::endl;
		std::cout << "Login:		" << this->_login << std::endl;
		std::cout << "Postal Address:	" << this->_postalAddress << std::endl;
		std::cout << "Email Address:	" << this->_emailAddress << std::endl;
		std::cout << "Phone Number:	" << this->_phoneNumber << std::endl;
		std::cout << "Birthday Date:	" << this->_birthdayDate << std::endl;
		std::cout << "Favorite Meal:	" << this->_favoriteMeal << std::endl;
		std::cout << "Underwear Color:" << this->_underwearColor << std::endl;
		std::cout << "Darkest Secret:	" << this->_darkestSecret << std::endl;
	} else {
		std::cout << "This Contact memory is empty." << std::endl;
	}
	return;
}

void	Contact::getIndex(void) {
	if (this->_isEmpty == 0) {
		this->_printIndexField(this->_firstName);
		this->_printIndexField(this->_lastName);
		this->_printIndexField(this->_nickname);
		std::cout << std::endl;
	} else {
		std::cout << "This Contact memory slot is empty." << std::endl;
	}
	return;
}

void	Contact::_printIndexField(char *value) {
	char	buff[11];
	int		len;
	int		offset;
	int		dot = 0;

	memset(buff, 32, 10);
	buff[10] = '\0';
	len = strlen(value);
	if (len > 10) {
		len = 10;
		dot = 1;
	}
	offset = 10 - len;
	for (int i = 0; i < len; i++) {
		buff[i + offset] = value[i];
	}
	if (dot)
		buff[9] = '.';
	std::cout << buff << "|";
}


void	Contact::_clearField(char *field) {
	for (int i = 0; i < 256; i++)
		field[i] = 0;
	return;
}

int		Contact::isEmpty(void) {
	return this->_isEmpty;
}
