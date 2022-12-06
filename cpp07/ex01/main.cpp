#include "iter.hpp"

int main (void)
{

	char array1[] = {'A','V','N','U','L','E'};
	iter(&array1, 6, &display);

	int array2[] = {9, 8, 7, 6, 5, 4};
	iter(&array2, 6, &display);
	return (0);
}