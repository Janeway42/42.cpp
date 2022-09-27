#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//PresidentialPardonForm informs that <target> has been pardoned by Zaphod Beeblebrox.

void presidentialTests(void)
{
	std::cout << "Presidential tests" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat M("kenedy", 5);
	Bureaucrat O("bush", 50);
	Form *C = new PresidentialPardonForm("homeee");
	std::cout << std::endl;
}

int main(void)
{
	shrubberyTests();
	robotomyTests();
	presidentialTests();

	Bureaucrat A("Jon", 10);
	Form AA("Jon's letter", 7);
	Bureaucrat B("Stone", -1);
	Bureaucrat C("Ana", 1);
	Bureaucrat D("Tom", 150);
	
	std::cout << std:: endl;
	A.decrementGrade();
	std::cout << A.getName() << " " << A.getGrade() << std::endl;
	std::cout << std:: endl;
	
	B.incrementGrade();
	std::cout << B.getName() << " " << B.getGrade() << std::endl;
	std::cout << std:: endl;
	
	C.incrementGrade();
	std::cout << C.getName() << " " << C.getGrade() << std::endl;
	std::cout << std:: endl;
	
	D.decrementGrade();
	std::cout << C.getName() << " " << D.getGrade() << std:: endl;
	std::cout << std:: endl;

	return (0);
}