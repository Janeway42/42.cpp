#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stack>
#include <string>
#include <iostream>
#include <fstream>

class rpn
{
	private:
		std::stack <int> _numbers;
		std::string _input;

	public:

		rpn();
		rpn(std::string input);
		~rpn();

		// int checkToken(std::string token);
		void runStack();
		void operation(int pos);
		// void printList();

		// --------------------
		std::string	spaceCleanup(std::string input);
		void	checkInput();
		int		checkOperand(char c);
		int		checkChar(char c);


		class rpnBadInput: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Bad Input");
				}
		};
};

#endif