#include <stdio.h>
#include <stdlib.h>

// Function to return gcd of a and b
int findGCD(int a, int b)
{
    if (a == 0)
        return b;
    return findGCD(b % a, a);
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int n1 = atoi(av[1]);
        int n2 = atoi(av[2]);
        if( n1 > 0 && n2 > 0)
            printf("%d", findGCD(n1, n2));
    }
    printf("\n");
    return(0);
}