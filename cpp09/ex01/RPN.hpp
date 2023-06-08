#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class rpn
{
	private:
		std::string _input;

	public:

		rpn();
		rpn(std::string input);
		rpn(const rpn& existing);
		~rpn();

		rpn& operator = (const rpn& existing);

		void runStack();
		void operation(std::stack <int> &numbers, int pos);

		std::string	checkInput(std::string input);
		int		checkOperand(char c);
		int		checkChar(char c);

		std::string getInput() const;

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