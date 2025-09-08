#include <unistd.h>

void    putnbr(int n)
{
        if (n > 10)
        {
                char c = (n % 10) + '0';
                putnbr(n / 10); // Metto prima rec_call così stampa nell'ordine corretto
                write(1, &c, 1);
        }
        else
        {
                char l = n + '0';   // Last figure or only figure
                write(1, &l, 1);
        }
}

int     main(int ac, char **av)
{
        (void)av; // Casto av per usarlo e non dare warning
        if (ac == 1)
                write(1, "0", 1);
        else
        {
                int n = ac - 1; // Numero degli argomenti
                putnbr(n);
        }
        write(1, "\n", 1);

}