#include "Span.hpp"

// --------constructors & destructors -----------
Span::Span(void):_size(0)
{
	std::cout << "default constructor called" << std::endl;
}

Span::Span(unsigned int N):_size(N)
{
	std::cout << "Constructor with input called" << std::endl;
}

Span::Span(const Span &existing):_size(existing._size)
{
	std::cout << "Copy assignment operator called" << std::endl;

	for(int i = 0; i < existing._size; i++)
	{
		_storage.push_back(existing._storage[i]);
	}
}

Span::~Span(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ------------copy assignment operator --------

Span& Span::operator = (const Span &existing)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &existing)
	{
		for(int i = 0; i < existing._size; i++)
		{
			_storage.push_back(existing._storage[i]);
		}
	}
	return (*this);
}

// ------------- public functions----------------

void Span::addNumber(int newElem)
{
	if (_storage.size() >= (size_t)_size)
		throw OutOfSpaceException();
	_storage.push_back(newElem);
}

int Span::shortestSpan(void)
{
	if (_storage.size() < 2)
		throw NoSpanException();

	int shortest = _storage[0] - _storage[1];
	for(size_t i = 0; i < _storage.size() - 1; i++)
	{
		for(size_t j = i + 1; i < _storage.size(); j++)
		{
			if (_storage[i] - _storage[j] < shortest)
				shortest = _storage[i] - _storage[j]; 
		}
	}
	return (shortest);
}

int Span::longestSpan(void)
{
	if (_storage.size() < 2)
		throw NoSpanException();

	int shortest = _storage[0] - _storage[1];
	for(size_t i = 0; i < _storage.size() - 1; i++)
	{
		for(size_t j = i + 1; i < _storage.size(); j++)
		{
			if (_storage[i] - _storage[j] > shortest)
				shortest = _storage[i] - _storage[j]; 
		}
	}
	return (shortest);
}

// void Span::rangeInterators(int element)
// {
// 	for (int n : element)
// 		_storage.push_back(n);
// }