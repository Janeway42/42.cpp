#include "RPN.hpp"

// ------------ Constructors & Destructors ------------

rpn::rpn(){}

rpn::rpn(std::string input)
{
	// std::cout << "input " << input << std::endl;

	size_t out = input.find(" ");
	try
	{
		_first = stoi(input.substr(0, out));
		// std::cout << "first: " << _first << std::endl;

		input = input.substr(out + 1);
		// std::cout << "input.substr: " << input << std::endl;

		while (out != std::string::npos)
		{
			out = input.find(" ");
			// std::cout << "\nout: " << out << std::endl;
			int val = stoi(input.substr(0, out));
			// std::cout << "val: " << val << std::endl;

			input = input.substr(out + 1);
			// std::cout << "input.substr: " << input << std::endl;

			out = input.find(" ");
			// std::cout << "\nout: " << out << std::endl;
			std::string temp;
			if (out == std::string::npos)
				temp = input;
			else
				temp = input.substr(0, out);
			// std::cout << "temp: " << temp << std::endl;

			if (checkToken(temp) == 1)
				throw rpnBadInput();

			if (out != std::string::npos)
				input = input.substr(out + 1);
			// std::cout << "\ninput.substr: " << input << std::endl;

			
			node new_elem;
			new_elem.val = val;
			new_elem.token = temp;
			_tokens.push_back(new_elem);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nFailed stoi. Unable to complete list!\n" << '\n';
	}	
}

rpn::~rpn(){}

// ------------ other functions ------------

void rpn::runList()
{
	
}

int rpn::checkToken(std::string token)
{
	if (token == " ")
		return (1);
	if (token.size() != 1)
		return (1);
	if (token != "+" && token != "-" && token != "*" && token != "/")
		return (1);
	return (0);
}

void rpn::printList()
{
	std::list<node>::iterator it = _tokens.begin();

	std::cout << "list: " << _first << " ";

	for (;it != _tokens.end(); it++)
		std::cout << it->val << " " << it->token << " ";
	std::cout << std::endl;
}
