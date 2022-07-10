#include "Phonebook.class.hpp"

Phonebook::Phonebook()
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i].index = i;
	this->count = 0;
	return ;
}

bool	Phonebook::book_add_contact(void)
{
	if (!this->_contacts[this->count % 8].add_contact())
		return (false);
	this->count++;
	return (true);
}

static int	search_index(int count)
{
	std::string	input;

	std::cout << "\033[35mPlease choose an index: \033[0m";
	if (!std::getline(std::cin, input, '\n') || std::cin.eof())
		return (-2);
	if (input.length() == 1
		&& (input[0] >= '0' && input[0] <= '7')
		&& (input[0] - '0' < count))
		return (input[0] - '0');
	std::cout << "\033[31mInvalid input.\033[0m" << std::endl;
	return (-1);
}

bool	Phonebook::book_search(void) const
{
	int	i;

	if (this->count == 0)
	{
		std::cout << "\033[31mEmpty phonebook!\033[0m" << std::endl;
		return (true);
	}
	std::cout << "Index     |First Name|Last Name |Nick Name " << std::endl; 
	for (i = 0; i < 8; i++)
		this->_contacts[i].display_search();
	i = -1;
	while (i == -1)
	{
		i = search_index(this->count);
		if (i == -2)
			return (false);
		if (i > -1)
			this->_contacts[i].display_contact_detail();
	}
	return (true);
}

Phonebook::~Phonebook(){}
