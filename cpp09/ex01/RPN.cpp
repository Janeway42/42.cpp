#include "RPN.hpp"

// ------------ Constructors & Destructors ------------

rpn::rpn()
{
	std::string input = "";
	_input = checkInput(input);
}

rpn::rpn(std::string input)
{
	_input = checkInput(input);
}

rpn::rpn(const rpn& existing)
{
	_input = existing.getInput();
}

rpn& rpn::operator = (const rpn& existing)
{
	if (this != &existing)
		_input = existing.getInput();
	return(*this);
}

// ------------------ Input Functions ------------------

std::string rpn::checkInput(std::string input)
{
	// remove front and back spaces 
	int start = 0;
	int end = 0;
	for (; input[start] == ' '; start++){}
	for(end = input.size() - 1; input[end] == ' '; end--){}
	input = input.substr(start, end + 1);

	// if only one character 
	if (input.size() == 1)
	{
		if (isdigit(input[0]) != 0)
			return (input);
		else 
			throw BadInput("size input == 1 but not a digit");
	}

	// check characters tokens and space 
	size_t token = 0;
	std::string allowed = "+-*/ ";
	for (int i = 0; input[i] != '\0'; i++)
	{
		token = allowed.find(input[i]);
		if (token == std::string::npos && isdigit(input[i]) == 0)
			throw BadInput("character not allowed");
	}

	// check nr of tokens versus nr of digits 
	if (isdigit(input[0]) == 0 || isdigit(input[2] == 0))
		throw rpnBadInput();
	int digits = 0;
	int tokens = 0;
	std::string tokensAllowed = "+-*/";
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isdigit(input[i]) != 0)
		{
			if (input[i + 1] != ' ')
				throw BadInput("wrong input after digit");;
			digits++;
		}
		else if (tokensAllowed.find(input[i]) != std::string::npos)
		{
			if (input[i + 1] != ' ' && input[i + 1] != '\0')
				throw BadInput("wrong input after token");
			tokens++;
		}
		else if (input[i] == ' ')
		{
			if (isdigit(input[i + 1]) == 0 && tokensAllowed.find(input[i + 1]) == std::string::npos)
				throw BadInput("wrong input after space");
		}
	}
	if (digits - 1 != tokens)
		throw BadInput("wrong ratio tokens to digits");
	return (input);
}

int rpn::checkChar(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int rpn::checkOperand(char c)
{
	for (int i = 0; TOKENS[i] != '\0'; i++)
	{
		if (TOKENS[i] == c)
			return (1);
	}
	return (0);
}

// ------------------ Run functions ------------------

void rpn::operation(std::stack <int> &numbers, int pos)
{
	int one;
	int two;
	int tempRes = 0;

	one = numbers.top();
	numbers.pop();
	two = numbers.top();
	numbers.pop();
			
	if (_input[pos] == '+')
		tempRes = two + one;
	else if (_input[pos] == '-')
		tempRes = two - one;
	else if (_input[pos] == '*')
		tempRes = two * one;
	else if (_input[pos] == '/')
		tempRes = two / one;
	numbers.push(tempRes);
}

void rpn::runStack()
{
	std::stack <int> numbers;
	if (_input.size() == 1)
	{
		std::cout << _input << std::endl;
		return ;
	}
	for(int i = 0; _input[i] != '\0'; i++)
	{
		for (; checkChar(_input[i]) == 1; i += 2)
		{
			try
			{
				std::string tempStr = &_input[i];
				int tempInt = stoi(tempStr);
				numbers.push(tempInt);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	
		if (_input[i + 1] == ' ')
			operation(numbers, i);
		else if (_input[i + 1] == '\0')
		{
			while (numbers.size() != 1)
				operation(numbers, i);
		}
	}
	std::cout << "result: " << numbers.top() << std::endl; 
}

// -------------------- Destructors -------------------

rpn::~rpn(){}

// -------------------- Getters -------------------

std::string rpn::getInput() const
{
	return (_input);
}
