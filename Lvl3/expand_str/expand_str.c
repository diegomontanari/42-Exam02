#include <unistd.h>

/* Controlla se un carattere è spazio/tab/newline (ASCII 9-13 o 32) */
int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

/* Controlla se ci sono altre parole dopo l'indice i */
int has_more_words(char *str, int i)
{
    while (str[i])
    {
        if (str[i] >= 32 && str[i] <= 126)
            return 1; // c'è ancora una parola
        i++;
    }
    return 0; // ultima parola
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }

    // salta spazi iniziali
    while (is_space(argv[1][i]))
        i++;

    while (argv[1][i])
    {
        // stampa parola
        while (argv[1][i] >= 32 && argv[1][i] <= 126)
            write(1, &argv[1][i++], 1);

        // salta spazi dopo la parola
        while (is_space(argv[1][i]))
            i++;

        // stampa 3 spazi solo se ci sono altre parole
        if (has_more_words(argv[1], i))
            write(1, "   ", 3);
    }

    write(1, "\n", 1);
    return 0;
}



