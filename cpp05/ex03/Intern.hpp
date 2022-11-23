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

	Form* makeForm(std::string nameForm, std::string target);
	int getType(std::string nameForm);

	Form* makeShrubbery(Form* newForm, std::string nameForm, std::string target);
	Form* makeRobotomy(Form* newForm, std::string nameForm, std::string target);
	Form* makePresidential(Form* newForm, std::string nameForm, std::string target);
	Form* makeDefault(Form* newForm);
};

#endif