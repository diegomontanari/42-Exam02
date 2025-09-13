#include <unistd.h>

int	simplified_atoi(char *str)
{
	int i = 0;
	int res = 0;

	// If this were a real atoi, I would need to skip spaces
	// and handle the sign, but it's not necessary here

	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return res;
}

void	print_hex(int n)
{
	char *base = "0123456789abcdef";
	
	if (n >= 16)
		print_hex(n / 16); // Recursive step to ensure LSF is printed before other elements
	char c = base[n % 16];
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = simplified_atoi(av[1]); // converts from string to int
        	print_hex(n);
	}
	write(1, "\n", 1);
	return (0);
}
