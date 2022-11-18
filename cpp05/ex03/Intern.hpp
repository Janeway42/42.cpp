#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Intern
{
private:

public:
	Intern(void);
	Intern(const Intern &existing);
	~Intern(void);

	Intern& operator = (const Intern &existing);

	Form* makeForm(std::string formName, std::string target);
};

#endif