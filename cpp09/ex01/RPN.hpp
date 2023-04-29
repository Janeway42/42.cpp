#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <iostream>
#include <fstream>

class node
{
	public:
		int val;
		std::string token;
		node *next;
};

class rpn
{
	private:
		int _first;
		std::list<node> _tokens;

	public:

		rpn();
		rpn(std::string input);
		~rpn();

		int checkToken(std::string token);
		void runList();
		void printList();


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