#include <unistd.h>

// 1: while salta spazi
// 2 : modified perché se numero < 0 interrompe il programma (mentre l'atoi normale lo processa cambiando segno)
// 3: convertire in int il restante numero

int	modified_atoi(char *nbr)
{
	int i = 0;
	int res = 0;
	while ((nbr[i] == ' ') || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{	
		if (nbr[i] == '+')
			i++;
		else
		{
			write(1, "0", 1);
			exit(0);
		}
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = res * 10 + (nbr[i] - '0'); // Ogni cifra viene aggiunta in fondo al nbr che stai costruendo
    		i++;
	} 
	return (res); // Non serve res * sign perché il segno non lo gestiamo
}	
	
	

// 1: 

int optimized_is_prime(int n) // Ottimizzato perché controlla solo fino a radice di n
{
    if (n < 2)
        return 0; // Return 0 se non è primo
    int i = 2;
    while (i * i <= n) // i * i è uno stratagemma intelligente perché non si può usare sqrt di math.h
    {
        if (n % i == 0) // Se riesco a fare una divisione senza resto significa non primo
            return 0;
        i++;
    }
    return 1; // Return 1 se è primo
}

int add_prime_sum(int n)
{
    int sum = 0;
    int i = 2;
    while (i <= n)
    {
        if (optimized_is_prime(i)) // Se i è primo lo aggiungi al totale
            sum += i;
        i++;
    }
    return sum;
}

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "0", 1);
		exit(0); // Uscita senza errore
	}
	int nbr = modified_atoi(av[1]); // Modified perché interrompe se minore di 0
	if (nbr > 1)
            ft_putnbr(add_prime_sum(nbr));
        else // 1 e 0 non sono primi
            write(1, "0", 1);
    write(1, "\n", 1);
    return 0;
}
