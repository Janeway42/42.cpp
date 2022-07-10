#include "Phonebook.class.hpp"

static std::string	input_to_upper(std::string input)
{
	for(int i = 0; input[i]; i++)
		input[i] = toupper(input[i]);
	return (input);
}

int	main(void)
{
	class Phonebook	the_book;
	std::string		input;
	int				terminate;

	terminate = 0;
	std::cout << "\033[1;35m******* Welcome! *******\033[0m" << std::endl;
	while (!terminate)
	{
		std::cout << "\033[35mHow can I help you?\033[0m" << std::endl;
		if (!std::getline (std::cin, input, '\n') || std::cin.eof())
			terminate = 1;
		if (!terminate)
		{
			input = input_to_upper(input);
			if (!input.compare("ADD"))
				terminate = 1 - the_book.book_add_contact();
			else if (!input.compare("SEARCH"))
				terminate = 1 - the_book.book_search();
			else if (!input.compare("EXIT"))
				break ;
			else
				std::cout << "\033[31mInvalid input.\033[0m" << std::endl;
		}
		if (terminate)
			std::cout << "\033[1;31m\nInvalid input. Terminate.\033[0m" << std::endl;
	}
	std::cout << "\033[1;35m******* Exiting. *******\033[0m" << std::endl;
	return (0);
}
