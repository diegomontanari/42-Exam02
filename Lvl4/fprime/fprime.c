#include <unistd.h>
#include <stdlib.h> // atoi

void    fprime(long n)
{
        long p = 2;

        while (n != p)
        {
                if (n % p == 0)
                {
                        printf("%ld*", p);
                        n /= p;
                }
                else
                        p++;
        } // Finito questo ciclo n = p, quindi lo stampiamo
        printf("%ld", p);
}

int     main(int ac, char **av)
{
        if (ac == 2)
        {
                long n = atoi(av[1]);
                if (n == 1)
                {
                        printf("1");
                        return 0;
                }
                else
                        fprime(n);
        }
        printf("\n"); 
        return 0;
}


/*
Do you want to do the recursive version of this exercise?

Then you need to define the function with p as a parameter and remove the while loop:

(note: here I am not using printf but it's the same thing)

void ft_fprime_rec(long n, long p)
{
    if (n == 1)
    {
        write(1, "1\n", 2);
        return ;
    }

    if (n % p == 0)
    {
        putnbr(p);
        ft_fprime_rec(n / p, p);
    }
    else
        ft_fprime_rec(n, p + 1);
}

And in main:

int main(int ac, char **av)
{
    if (ac == 2)
    {
        long n = atoi(av[1]);
        ft_fprime_rec(n, 2); // As you see, I pass 2 arguments and p starts at 2
    }
    return 0;
}
*/
