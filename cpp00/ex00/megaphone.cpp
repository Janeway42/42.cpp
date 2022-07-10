#include <iostream>
#include <cstring>

void	my_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(i = 1; i < argc; i++)
			my_toupper(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}