#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat A("Jon", 10);
	Bureaucrat B("Stone", -1);
	Bureaucrat C("Ana", 1);
	Bureaucrat D("Tom", 300);
	
	std::cout << std:: endl;
	A++;
	std::cout << A.getName() << " " << A.getGrade() << std::endl;
	std::cout << std:: endl;
	
	++B;
	std::cout << B.getName() << " " << B.getGrade() << std::endl;
	std::cout << std:: endl;
	
	--C;
	std::cout << C.getName() << " " << C.getGrade() << std::endl;
	std::cout << std:: endl;
	
	D--;
	std::cout << C.getName() << " " << D.getGrade() << std:: endl;
	std::cout << std:: endl;

	return (0);
}