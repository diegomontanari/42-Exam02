#include <unistd.h>

// NOTE: the empty string is hidden in any string, so if (!s1) we can return 1 and newline 
// NOTE: remember to protect your indexes from segmentation faults!!

int	ft_hidenp(char *s1, char *s2)
{
	int i = 0; // index for s1
	int j = 0; // index for s2

	// Loop while both strings still have characters
	while (s1[i] && s2[j])
	{
        	// If current characters match, move forward in s1 (this works but remember that this means the the pointer is empty, if I wanted to check if str = " " I should have used if (!str[0])
        	if (s1[i] == s2[j])
            		i++;
        	// Always move forward in s2
        	j++;
    	}

    	// If we consumed all of s1, it means s1 is hidden in s2
    	if (s1[i] == '\0')
        	return (1);
    	return (0);
}


int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1); // Wrong format prints only new line
		return (0);
	}
	char *s1 = av[1];
	char *s2 = av[2];
	if ((!s1) || (ft_hidenp(s1, s2))) // Se s1 è hidden in s2 (!s1 is hidden in any string)
	{
		write(1, "1\n", 2);
		return (0);
	}
	write(1, "0\n", 2); // s1 non hidden in s2 prints 0 and new line
	return (0);
}
