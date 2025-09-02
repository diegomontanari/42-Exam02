// This ex. combines nested scanning, use of a lookup table and uniqueness condition
// So the “true” pattern of the exercise is: "Intersection search between sets with duplicate checking via a lookup table."

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int i = 0;
	int j;
	char seen[256] = {0}; // If I don't use {0}, the array elements aren't initialized and may contain garbage values. But in C, If an array is initialized with fewer values than its size, all unspecified elements are automatically set to 0, (for example: char ar[256] = {4, 3}; sets ar[0] = 4, ar[1] = 3 and all the remaining ones to 0.

	while (s1[i])
	{
		j = 0; // Reset s2 to start again 
		while (s2[j])
		{
			if (s1[i] == s2[j] && !seen[(unsigned char)s1[i]]) // Signed chars above 127 are negative and we cannot have negative indexes, so we need unsigned chars
			{
				write(1, &s1[i], 1);
				seen[(unsigned char)s1[i]] = 1; // Each char is 1 byte (8 bits), so 2**8 =256 possible values; casting to unsigned char ensures safe indexing in seen[256]
				break;
			}
			j++;
		}
		i++;
	}



}





int main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return 0;
}
