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

int skip_word(char *str, int i)
{
    while (str[i] && !is_delimiter(str[i]))
        i++;
    return i;
}

void    rostring(char *str)
{
        int i = 0;
        int start;
        int first = 0;
        int end;

        // Isoliamo la prima parola
        i = skip_space(str, i);
        start = i;
        i = skip_word(str, i);
        end = i; // end è indice dopo parola ma va bene perché end - start fa proprio len parola (ricorda che intervallo = start (incluso) - end (escluso)

        // Scorriamo e stampiamo tutte le altre parole lavorando su spazi
        i = skip_space(str, i);
        while (str[i])
        {
                if (!is_delimiter(str[i])) // Se ho una parola
                {
                        if (first)
                                write(1, " ", 1);
                        while (str[i] && !is_delimiter(str[i])) // Stampo finché è parola
                                write(1, &str[i++], 1);
                        first = 1; // Flag che ho stampato almeno una parola
                }
                else
                        i++;
        }

        // Stampiamo la prima parola
        if (first)
                write(1, " ", 1);
        write(1, &str[start], end - start); // end - start come prima è la len della parola
}


int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}
