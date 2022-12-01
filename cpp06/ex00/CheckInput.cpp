#include "CheckInput.hpp"

int checkFloat(std::string str)
{
	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
	{
		std::string substrTemp;
		if (str[0] == '+' || str[0] == '_')
			substrTemp = str.substr(1, str.length() - 1);
		if (checkDouble(substrTemp) == 1)
			return (1);
		return (0);
	}
	return (1);
}

int checkDouble(std::string str)
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
	if (dot != 1)
		return (1);
	return (0);
}

int checkDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit((int)str[i]) == 0)
			return (1);
	}
	return (0);
}

int checkChar(std::string str)
{
	if (str.length() == 1 && isalpha((int)str[0]) != 0)
		return (0);
	return (1);
}

int checkPrintable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isprint((int)str[i]) == 0)
			return (1);
	}
	return (0);
}
