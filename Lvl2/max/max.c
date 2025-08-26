#include <limits.h>

int             max(int* tab, unsigned int len)
{
	int i = 0;
	int max = INT_MIN;
	
	if (!tab || len == 0) // Mi ero scordato di mettere check len = 0 che è fondamentale
		return 0;
	
	while (i < len) // Or i <= len - 1 (perché parte da zero i)
	{
		if (tab[i] >= max)
			max = tab[i];
		i++;
	}
	return max;
}

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
