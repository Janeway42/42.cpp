#include <iostream>
#include <string.h>
#include "YellowPages.hpp"

Contact::   Contact(void)
{
    return;
}

Contact::   ~Contact(void)
{
    return;
}

void	Contact::writeContact(void)
{
	std::cout << "First Name: ";
	std::getline(std::cin, this->_firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->_phoneNumber);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->_secret);

}

void    Contact:: printRow(int  i)
{
    std::cout << "|";
    std::cout << "         ", std::cout << i, std::cout << "|";
    std::cout << _firstName, std:: cout << "|";
    std::cout << _lastName, std::cout << "|";
    std::cout << _nickname, std::cout << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" <<std::endl;
}

void	Contact:: printContact()
{
	std::cout << "First Name: ", std::cout << _firstName << std::endl;
	std::cout << "Last Name: ", std::cout << _lastName << std::endl;
	std::cout << "Nickname: ", std::cout << _nickname << std::endl;
	std::cout << "Telephone: ", std::cout << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: ", std::cout << _secret << std::endl;
}
