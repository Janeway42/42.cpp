#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>

// std::stack is a class that contains a container element of type std::deque
// class stack is limited in the functions it can utilize
// class deque however has everything required, unfortunately there is no inheritance here

// template <
//     class T,
//     class Container = std::deque<T>
// > class stack;

template <typename T>
class MutantStack: public std::stack<T>
{
	private:
	public:
		MutantStack(void): std::stack<T>()
		{
			std::cout << "Default constructor called" << std::endl;
		}
		MutantStack(const MutantStack &existing)
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = existing;
		}
		~MutantStack(void)
		{
			std::cout << "Destructor called" << std::endl;
		}

		MutantStack& operator =(const MutantStack &existing)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &existing)
				this->c = existing->c;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		// typedef typename std::deque<T>::iterator iterator;

		iterator begin(void)
		{
			return(this->c.begin());
		}

		iterator end(void)
		{
			return(this->c.end());
		}

};

#endif