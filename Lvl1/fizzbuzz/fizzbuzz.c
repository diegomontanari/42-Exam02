#include <unistd.h>

void	putnbr(int n)
{
	char c;
	
	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0'; // Ricorda che i moduli con 10 isolano sempre la cifra meno significativa del numero. Tecnica utile // Ricorda che i moduli con 10 isolano sempre la cifra meno significativa del numero. Tecnica utile..
	write(1, &c, 1);
}


void	fizzbuzz()
{
	int n = 1;
	
	while (n <= 100)
	{
		
		if ((n % 3 == 0) && (n % 5 == 0))
			write(1, "fizzbuzz", 8);

		else if (n % 3 == 0)
			write(1, "fizz", 4);

		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(n);  // Qua serve un mini itoa

		write(1, "\n", 1);
		n++;
	}
}

int	main()
{
	fizzbuzz();
	return 0;
} 
