#include "Span.hpp"

// --------constructors & destructors -----------
Span::Span(void):_size(0)
{
	std::cout << "Default constructor called" << std::endl;
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

	std::vector<int> output(_size);
	std::sort(_storage.begin(), _storage.end());
	std::adjacent_difference(_storage.begin(), _storage.end(), output.begin());
	int shortest = *std::min_element(output.begin() + 1, output.end());
	return (shortest);
}

int Span::longestSpan(void)
{
	if (_storage.size() < 2)
		throw NoSpanException();

	std::sort(_storage.begin(), _storage.end());
	int shortest = abs(*(_storage.end() - 1) - *_storage.begin());
	return (shortest);
}

void Span::printStorage(void)
{
	for (std::vector<int>::iterator it = _storage.begin(); it < _storage.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int Span::getSize(void)
{
	return (this->_size);
}

std::vector<int> Span::getStorage(void)
{
	return (this->_storage);
}