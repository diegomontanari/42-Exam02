#include <unistd.h>
#include <stdlib.h>

// Ritorna 1 se il carattere è uno spazio, tabulazione o newline.
// L'unico scopo di questa funzione è bloccare i while delle altre
int is_delimiter(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}


// Salta i delimitatori andando all’indietro nella stringa `str`
// partendo dalla posizione `i`, e ritorna l’indice del primo carattere non delimitatore.
int skip_space(char *str, int i)
{
    while (i >= 0 && is_delimiter(str[i]))
        i--;
    return i;
}

// Salta una parola andando all’indietro nella stringa `str`
// partendo dalla posizione `i`, e ritorna l’indice del carattere
// immediatamente precedente la parola.
int skip_word(char *str, int i)
{
    while (i >= 0 && !is_delimiter(str[i])) // Secondo questa logica se non è delimiter è parola, ma è proprio così che specifica il subject quindi proseguiamo
        i--;
    return i;
}

int	ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}


void	ft_rev_wstr(char *str)
{
	int i = ft_strlen(str) - 1; // Len salvata in i
	int start; // Carattere prima di inizio parola
	int first = 0; // Flag prima parola che evita di stampare il primo spazio
	
	while (i >= 0)
	{
		i = skip_space(str, i); // Salto gli spazi
        if (i < 0)
            	break; // This manages av[1] = "   " and also av[1] = "     Word Parola Palabra" as skip_space will skip until i = -1
		if (first)
			write(1, " ", 1);
		start = skip_word(str, i); // ha valore di spazio prima di parola
		write(1, &str[start + 1], i - start); // Di tt str stampa da start + 1 per esattamente i - start caratteri (ultimo carattere parola - spazio prima di parola = lunghezza parola)
		i = start; // Faccio ripartire dallo spazio prima
		first = 1; // Da ora in poi se first = 1 si stampano gli spazi t
	}
}

int     main(int ac, char **av)
{
        if (ac == 2)
                ft_rev_wstr(av[1]);
        write(1, "\n", 1);
        return 0;
}
