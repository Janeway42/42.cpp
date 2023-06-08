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
	if (input.size() == 1 && checkChar(input[0]) == 1)
		return (input);
	if (checkChar(input[0]) == 0 || checkChar(input[2]) == 0)
	{
		std::cout << "Baaaaad input\n";
	}
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (checkChar(input[i]) == 1 && input[i + 1] != ' ')  // if number and not space after 
			throw rpnBadInput();
		else if (checkOperand(input[i]) == 1 && (input[i + 1] != ' ' && input[i + 1] != '\0'))
			throw rpnBadInput();
		if (input[i + 1] == '\0')
			break ;
	}
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
	std::string operands = "+-*/";
	for (int i = 0; operands[i] != '\0'; i++)
	{
		if (operands[i] == c)
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
	std::cout << "output: " << numbers.top() << std::endl; 
}

// -------------------- Destructors -------------------

rpn::~rpn(){}

// -------------------- Getters -------------------

std::string rpn::getInput() const
{
	return (_input);
}
