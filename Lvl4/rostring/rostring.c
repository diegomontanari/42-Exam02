#include <unistd.h>

int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int skip_space(char *str, int i)
{
    while (str[i] && is_delimiter(str[i]))
        i++;
    return i;
}

void rostring(char *str)
{
    int i = 0;
    int start;
    int end;
    int first = 0;

    // Isola la prima parola
    i = skip_space(str, i);
    start = i;
    while (str[i] && !is_delimiter(str[i]))
        i++;
    end = i;

    // Scorre il resto della stringa e stampa le altre parole
    i = skip_space(str, i);
    while (str[i])
    {
        if (!is_delimiter(str[i]))
        {
            if (first)
                write(1, " ", 1);
            while (str[i] && !is_delimiter(str[i]))
                write(1, &str[i++], 1);
            first = 1;
        }
        else
            i++;
    }

    // Stampa la prima parola alla fine
    if (first)
        write(1, " ", 1);
    write(1, str + start, end - start);
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}
