#include "CheckInput.hpp"
#include "ProcessItem.hpp"

int processChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout.precision(3);
	std::cout << "float: " << std::showpoint << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::showpoint << static_cast<double>(c) << std::endl;
	return (0);
}

int processFloat(std::string str)
{
	try
	{
		float temp = stof(str);

		std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(temp);
		std::cout.precision(3);
		std::cout << "float: " << std::showpoint << temp << std::endl;
		std::cout << "double: " << std::showpoint << static_cast<double>(temp) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Stof failed" << std::endl;
		return (1);
	}
	return (0);
}

int processInt(std::string str)
{
	try 
	{
		int temp = stoi(str);

		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << temp << std::endl;
		std::cout.precision(3);
		std::cout << "float: " << std::showpoint << static_cast<float>(temp) << "f" << std::endl;
		std::cout << "double: " << std::showpoint<< static_cast<double>(temp) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Stoi failed" << std::endl;
		return (1);
	}
	return (0);
}

int processDouble(std::string str)
{
	try
	{
		double temp = stod(str);

		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(temp) << std::endl;
		std::cout.precision(3);
		std::cout << "float: " << std::showpoint<< static_cast<float>(temp) << "f" << std::endl;
		std::cout << "double: " << std::showpoint << temp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Stod failed" << std::endl;
		return (1);
	}
	return (0);
}

// int outputNAN(void)
// {

// }

// int comapreSpecials(std::string str, std::string array)
// {
// 	std::string specials1[] = {"nan", "nanf"};

// 	for(int i = 0; i < array->length(); i++)
// 	{
// 		if (str.compare(array[i]) == 0)
// 			return (1);
// 	}
// 	return (0);
// }

int processInput(std::string str)
{
	// if (compareSpecials(str, specialNAN) == 1)
	// 	return (outputNAN());
	// if (compareSpecials(str, specialINF) == 1)
	// 	return (outputINF());

	//char
	if (checkChar(str) == 0)
		return (processChar(str[0]));
	else
	{
		//float
		if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
			return (processFloat(str));
		//int
		else if (checkDigit(str) == 0)
			return (processInt(str));
		//double
		else if (checkDouble(str) == 0)
			return (processDouble(str));
		else
		{
			std::cout << "Wrong input. Unable to process" << std::endl;
			return (1);
		}
	}
	return (0);
}