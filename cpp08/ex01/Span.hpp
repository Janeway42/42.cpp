#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

template <typename T> 
void printContainer(T element)
{
	for (typename T::iterator it = element.begin(); it != element.end(); it++)
	{
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

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

		void printStorage(void);
		int getSize(void);
		std::vector<int> getStorage(void);
		
	template <typename T> 
	void rangeIterators(T element)
	{
		for (typename T::iterator it = element.begin(); it != element.end(); it++)
		{
			_storage.push_back(*it);
		}
	}

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