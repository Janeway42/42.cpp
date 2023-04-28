#include "RPN.hpp"

// ------------ Constructors & Destructors ------------

rpn::rpn(){}

rpn::rpn(std::string input)
{
	size_t out = input.find(" ");
	try
	{
		_first = stoi(input.substr(0, out));
		input = input.substr(out + 1);
		while (input != "")
		{
			out = input.find(" ");
			int val = stoi(input.substr(0, out));
			input = input.substr(out + 1);
			out = input.find(" ");
			std::string temp = input.substr(0, out);
			if (checkToken(temp) == 1)
				throw rpnBadInput();
			input = input.substr(out + 1);
			
			node new_elem;
			new_elem.val = val;
			new_elem.token = temp;
			_tokens.push_back(new_elem);	
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed stoi. Unable to complete list!\n" << '\n';
	}	
}

rpn::~rpn(){}

// ------------ other functions ------------

int rpn::checkToken(std::string token)
{
	if (token == " ")
		return (1);
	if (token.size() != 1)
		return (1);
	if (token != "+" || token != "-" || token != "*" || token != "/")
		return (1);
	return (0);
}

void rpn::printList()
{
	std::list<node>::iterator it = _tokens.begin();

	std::cout << _first << " \n";
	it++;

	for (;it != _tokens.end(); it++)
		std::cout << it->val << " " << it->token << std::endl;
}
