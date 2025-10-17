#include <unistd.h>

void    putchar(char c)
{
        write(1, &c, 1);
}

void    camel_to_snake(char *str)
{
        int i = 0;
        char c;

        while (str[i])
        {
                c = str[i];
                if (c >= 'A' && c <= 'Z')
                {
                        ft_putchar('_');
                        ft putchar(c + 32);
                }
                else
                        putchar(c);
                i++;
        }
}

int     main(int ac, char **av)
{
        if (ac == 2)
                camel_to_snake(av[1]);
        write(1, "\n", 1);
        return 0;
}
