#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stack>
#include <string>
#include <iostream>
#include <fstream>

#define PLUS
#define MIN "-"
#define MULTI "*"
#define DIV "/"
#define TOKENS "+-*/"

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

		class BadInput: public std::exception
        {
            private:
                std::string _errorMessage;

            public:
                // explicit: https://leimao.github.io/blog/CPP-Explicit-Constructor/
                explicit BadInput(const std::string& message) throw()
                {
                    _errorMessage = message;
                }
                virtual const char* what() const throw()
                {
                    return (_errorMessage.c_str());
                }
                virtual ~BadInput() throw(){}
        };
};

#endif