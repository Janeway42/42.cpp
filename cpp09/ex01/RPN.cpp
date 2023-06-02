#include "RPN.hpp"

// ------------ Constructors & Destructors ------------

rpn::rpn()
{
	std::string input = "";
	_input = spaceCleanup(input);
	checkInput();
}

rpn::rpn(std::string input)
{
	_input = spaceCleanup(input);
	checkInput();
}

// ------------------ Input Functions ------------------

std::string rpn::spaceCleanup(std::string input)
{
	std::cout << "input: |" << input << "|" << std::endl;

	int size = input.size();
	int i = 0;
	int j = 0;

	for (; input[i] == ' '; i++){}
	for (; input[(size - 1) - j] == ' '; j++){}

	std::string temp = input.substr(i, size - i - j);
	// std::cout << "temp: |" << temp << "|" << std::endl;

	return (temp);
}

void rpn::checkInput()
{
	std::cout << "input: |" << _input << "|" << std::endl;
	if (_input.size() == 1 && checkChar(_input[0]) == 1)
		return ;
	if (checkChar(_input[0]) == 0 || checkChar(_input[2]) == 0)
	{
		std::cout << "Baaaaad input\n";
		throw rpnBadInput();
	}
	for (int i = 0; _input[i] != '\0'; i++)
	{
		// std::cout << "i = " << i << std::endl;

		if (checkChar(_input[i]) == 1 && _input[i + 1] != ' ')  // if number and not space after 
		{
			std::cout << "one\n";
			throw rpnBadInput();
		}
		else if (checkOperand(_input[i]) == 1 && (_input[i + 1] != ' ' && _input[i + 1] != '\0'))
		{
			std::cout << "two\n";
			throw rpnBadInput();
		}
		if (_input[i + 1] == '\0')
			return ;

	}
}

int rpn::checkChar(char c)
{
	// std::cout << "char checkChar: " << c << std::endl;
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int rpn::checkOperand(char c)
{
	std::string operands = "+-*/";
	for (int i = 0; operands[i] != '\0'; i++)
	{
		if (operands[i] == c)
			return (1);
	}
	return (0);
}

// ------------------ Run functions ------------------

void rpn::operation(int pos)
{
	int one;
	int two;
	int tempRes = 0;

	one = _numbers.top();
	_numbers.pop();
	two = _numbers.top();
	_numbers.pop();
			
	if (_input[pos] == '+')
		tempRes = two + one;
	else if (_input[pos] == '-')
		tempRes = two - one;
	else if (_input[pos] == '*')
		tempRes = two * one;
	else if (_input[pos] == '/')
		tempRes = two / one;
	_numbers.push(tempRes);
	// std::cout << "tempRes: " << tempRes << std::endl;
}

void rpn::runStack()
{
	if (_input.size() == 1)
	{
		std::cout << _input << std::endl;
		return ;
	}
	for(int i = 0; _input[i] != '\0'; i++)
	{
		for (; checkChar(_input[i]) == 1; i += 2)
		{
			// std::cout << "i runStack: " << i << std::endl;
			try
			{
				std::string tempStr = &_input[i];
				int tempInt = stoi(tempStr);
				// std::cout << "tempInt: " << tempInt << std::endl;
				_numbers.push(tempInt);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		// std::cout << "runStack point: " << _input[i] << std::endl;
	
		if (_input[i + 1] == ' ')
			operation(i);
		else if (_input[i + 1] == '\0')
		{
			while (_numbers.size() != 1)
				operation(i);
		}
	}
	std::cout << "output: " << _numbers.top() << std::endl; 
}

// -------------------- Destructors -------------------

rpn::~rpn(){}