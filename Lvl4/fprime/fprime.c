#include <unistd.h>
#include <stdlib.h> // atoi

void putnbr(long n)
{
    char c;
    
    if (n >= 10)
        putnbr(n / 10); // Recursive call
    c = (n % 10) + '0'; // Convert LSF (Less Significant Figure) to char
    write(1, &c, 1);
}

void ft_fprime(long n)
{
    long p = 2;

    // Subjects tells input > 0, no need to check n <= 0
    if (n == 1)
    {
        write(1, "1\n", 2);
        return ;
    }

    while (n > 1) // The base case of prime factorization is n = 1, so stop when n is no longer greater than 1
    {
        if (n % p == 0)
        {
            putnbr(p);
            n /= p;  // Division without recursion
        }
        else
            p++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        long n = atoi(av[1]);
        ft_fprime(n);
    }
    write(1, "\n", 1);
    return 0;
}

/*
Do you want to do the recursive version of this exercise?

Then you need to define the function with p as a parameter and remove the while loop:

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
