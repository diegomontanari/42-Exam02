void	putnbr(long n)
{
	char c;
	
	if (n >= 10)
		putnbr(n / 10); // Chiamata ricorsiva
	c = (n % 10) + '0'; // Conversione in char del LSF (Less Significant Figure)
	write(1, &c, 1);
}

void	ft_fprime(long n)
{
	
	// Subjects tells input > 0, no need to check n <= 0
	if (n == 1)
	{
		write(1, "1\n", 2);
		return ;
	}
	
	while (n > 1) // Il caso base della scomposizione in fattori primi è n = 1, quindi mi fermo quando n non è più maggiore di 1
	{
		if (n % p == 0)
		{
			putnbr(long p);
			ft_prime(n / p);
		}
		else
			p++;
	}
}



int	main(int ac, char **av)
{
	long p = 2;
	
	if (ac == 2)
	{
		long n = atoi(av[1]);
		ft_fprime(n, p);
	write(1, "\n", 1);
	return 0;
}
