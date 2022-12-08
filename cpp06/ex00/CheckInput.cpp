#include "CheckInput.hpp"

int checkChar(std::string str)
{
	if (str.length() == 1 && isascii((int)str[0]) != 0 && isdigit((int) str[0]) == 0)
		return (0);
	return (1);
}

// -------------------------------------------------------------

int checkDot(std::string str)
{
	int dot = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit((int)str[i]) == 0)
		{
			if ((str[i]) == '.')
				dot++;
			else
				return (1);
		}
	}
	if (dot > 1)
		return (1);
	return (0);
}

int checkFloat(std::string str)
{
	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
	{
		std::string substrTemp;
		if (str[0] == '+' || str[0] == '-')
			substrTemp = str.substr(1, str.length() - 2);
		else
			substrTemp = str.substr(0, str.length() - 2);
		if (checkDot(substrTemp) == 1)
			return (1);
		return (0);
	}
	return (1);
}

int checkDouble(std::string str)
{
	std::string substrTemp;
	if (str[0] == '+' || str[0] == '-')
		substrTemp = str.substr(1, str.length() - 2);
	else
		substrTemp = str.substr(0, str.length() - 2);
	if (checkDot(substrTemp) == 1)
		return (1);
	return (0);
}

// -------------------------------------------------------------


int checkDigit(std::string str)
{
	std::string substrTemp;
	if (str[0] == '+' || str[0] == '-')
		substrTemp = str.substr(1);
	else
		substrTemp = str;
	for (size_t i = 0; i < substrTemp.length(); i++)
	{
		if (isdigit((int)substrTemp[i]) == 0)
			return (1);
	}
	return (0);
}
