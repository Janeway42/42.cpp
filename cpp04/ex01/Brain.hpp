#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain(void);
	Brain(const Brain &existing);
	~Brain(void);

	Brain& operator = (Brain const &existing);
	
	void printIdeas(void);
};

#endif