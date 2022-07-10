/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   phonebook.class.cpp                               e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/03/24 17:21:26 by dries             *8*   8   *8*          */
/*   Updated: 2021/03/24 17:21:26 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <string.h>

Phonebook::Phonebook(void) {
	char	buff[8];

	std::cout << "Welcome to the Phonebook 3000: Contact Management System" << std::endl;
	while (1) {
		bzero(buff, 8);
		std::cout << "$";
		std::cin >> buff;
		buff[7] = '\0';
		if (strcmp(buff, "EXIT") == 0)
			break;
		else if (strcmp(buff, "ADD") == 0)
			this->_add();
		else if (strcmp(buff, "SEARCH") == 0)
			this->_search();
		else
			std::cout << "Invalid input. ADD | SEARCH | EXIT" << std::endl;
	}
	return;
}

Phonebook::~Phonebook(void) {
	return;
}

void	Phonebook::_add(void) {
	int		wrote = 0;
	char	buff[32];

	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].isEmpty() == 1) {
			this->_contacts[i].writeContact();
			wrote = 1;
			break;
		}
	}
	if (wrote == 0) {
		this->_printIndex();
		while (1) {
			bzero(buff, 32);
			std::cout << "Contacts list full, enter an index to delete, or 9 to cancel: ";
			std::cin >> buff;
			if (buff [1] == '\0' && (buff[0] <= '9' && buff[0] >= '0')) {
				if (buff[0] != '9') {
					this->_contacts[buff[0] - 48].clearContact();
					this->_contacts[buff[0] - 48].writeContact();
				}
				break;
			}
			std::cout << "Invalid input." << std::endl;
		}
	}
	return;
}

void	Phonebook::_search(void) {
	char	buff[32];

	this->_printIndex();
	while (1) {
		bzero(buff, 32);
		std::cout << "Enter a contact index to display, or 9 to cancel: ";
		std::cin >> buff;
		if (buff [1] == '\0' && (buff[0] <= '9' && buff[0] >= '0')) {
			if (buff[0] != '9')
				this->_contacts[buff[0] - 48].getContact();
			break;
		}
		std::cout << "Invalid input." << std::endl;
	}
	return;
}

void	Phonebook::_printIndex(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].isEmpty() == 0) {
			std::cout << "|" << "         " << i << "|";
			this->_contacts[i].getIndex();
		}
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}
