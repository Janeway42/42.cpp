#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		int _size;
		std::vector<int> _storage;

	public: 
		Span(void);
		Span(unsigned int N);
		Span(const Span &existing);
		~Span(void);

		Span& operator = (const Span &existing);

		void addNumber(int newElem);
		int shortestSpan(void);
		int longestSpan(void);
		// void rangeInterators(int element);

	class OutOfSpaceException: public std::exception
	{
		const char * what() const throw()
		{
			return ("Storage full!");
		}	 
	};

	class NoSpanException: public std::exception
	{
		const char * what() const throw()
		{
			return ("No Span to be found!");
		}	 
	};
};

#endif