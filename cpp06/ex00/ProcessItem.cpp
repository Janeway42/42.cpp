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

		std::cout << "char: Non displayable" << std::endl;
		if (temp > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(temp) << std::endl;
		std::cout.precision(3);
		std::cout << "float: " << std::showpoint << temp << std::endl;
		if (temp > DBL_MAX)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::showpoint << static_cast<double>(temp) << std::endl;		
	}	
	catch(std::out_of_range const& ex)
    {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
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
	catch(std::out_of_range const& ex)
    {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
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
		if (temp > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(temp) << std::endl;
		std::cout.precision(3);
		std::cout << "float: " << std::showpoint<< static_cast<float>(temp) << "f" << std::endl;
		std::cout << "double: " << std::showpoint << temp << std::endl;
	}
	catch(std::out_of_range const& ex)
    {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
    }
	catch(const std::exception& e)
	{
		std::cout << "Stod failed" << std::endl;
		return (1);
	}
	return (0);
}


int outputNAN(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	return (0);
}

int outputINF(char sign)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << sign << "inff" << std::endl;
	std::cout << "double: " << sign << "inf" << std::endl;
	return (0);
}

int compareINF(std::string str, const std::string array[], int size)
{
	for (int i = 0; i < size != '\0'; i++)
	{
		if (str == array[i])
			return (0);
	}
	return (1);
}

int processInput(std::string str)
{
	const std::string array1[] = {"nan", "nanf"};
	const std::string array2[] = {"+inf", "-inf", "+inff", "-inff"};

	if (compareINF(str, array1, 2) == 0)
		return (outputNAN());
	if (compareINF(str, array2, 4) == 0)
		return (outputINF(str[0]));

	//char
	if (checkChar(str) == 0)
		return (processChar(str[0]));
	else
	{
		//float
		if (checkFloat(str) == 0)
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