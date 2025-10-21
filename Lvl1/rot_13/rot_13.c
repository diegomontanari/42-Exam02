#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}	

void	rot_13(char *str)
{
	int i = 0;
	char c;
	
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = 'A' + (str[i] - 'A' + 13) % 26; // Pattern base, range relativo, offset e cerchio, ovvero modulo (fantastico!)
			putchar(c);
		}		
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			c = 'a' + (str[i] - 'a' + 13) % 26; // Pattern base, range relativo, offset e cerchio, ovvero modulo (fantastico!)
                        putchar(c);
		}
		else
		{
			c = str[i];
			putchar(c);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write(1, "\n", 1);
	return 0;
}
