#include "Contact.class.hpp"

Contact::Contact(void){}

bool			Contact::add_contact(void)
{
	std::cout << "\033[35mInput first name: \033[0m";
	if (!std::getline(std::cin, this->_first_name, '\n') || std::cin.eof() || !this->_first_name.length())
		return (false);
	std::cout << "\033[35mInput last name: \033[0m";
	if (!std::getline(std::cin, this->_last_name, '\n') || std::cin.eof() || !this->_last_name.length())
		return (false);
	std::cout << "\033[35mInput nick name: \033[0m";
	if (!std::getline(std::cin, this->_nick_name, '\n') || std::cin.eof() || !this->_nick_name.length())
		return (false);
	std::cout << "\033[35mInput phone number: \033[0m";
	if (!std::getline(std::cin, this->_phone_number, '\n') || std::cin.eof() || !this->_phone_number.length())
		return (false);
	std::cout << "\033[35mInput darkest secret: \033[0m";
	if (!std::getline(std::cin, this->_darkest_secret, '\n') || std::cin.eof() || !this->_darkest_secret.length())
		return (false);
	std::cout << "\033[32mContact added successfully!\033[0m" << std::endl;
	return (true);
}

static std::string		modify_str(std::string	old_str)
{
	std::string	str;
	
	str.assign(old_str);
	if (str.length() > 10){
		str.resize(9);
		str += ".";
	}
	return (str);
}

void	Contact::display_search(void) const
{
	if (this->_first_name.length() == 0)
		return ;
	std::cout
		<< std::setw(10) << (int)this->index				<< "|"
		<< std::setw(10) << modify_str(this->_first_name) 	<< "|"
		<< std::setw(10) << modify_str(this->_last_name)  	<< "|"
		<< std::setw(10) << modify_str(this->_nick_name)  	<< std::endl;
}

void	Contact::display_contact_detail(void) const
{
	std::cout << "Index:		" << (int)this->index 		<< std::endl;
	std::cout << "First name: 	" << this->_first_name 		<< std::endl;
	std::cout << "Last name: 	" << this->_last_name 		<< std::endl;
	std::cout << "Nick name: 	" << this->_nick_name 		<< std::endl;
	std::cout << "Phone number: 	" << this->_phone_number 	<< std::endl;
	std::cout << "Darkest secret:	" << this->_darkest_secret 	<< std::endl;
}

Contact::~Contact(void){}
