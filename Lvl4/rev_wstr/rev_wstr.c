// 1 LINER: Print the words of a string in reverse order, keeping the words themselves intact.
// REASONING QUESTIONS: How can I? The best way is to iterate backwards on the string and print each work.
// REASONING 2: a word is separated by: spaces, tabs, start/end of string.
// NOTE: Words will always be separated by one space in tests.

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
int rskip_space(char *str, int i)
{
    while (i >= 0 && is_delimiter(str[i]))
        i--;
    return i;
}

// Salta una parola andando all’indietro nella stringa `str`
// partendo dalla posizione `i`, e ritorna l’indice del carattere
// immediatamente precedente la parola.
int rskip_word(char *str, int i)
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
		i = rskip_space(str, i); // Salto gli spazi
        	if (i < 0)
            		break;
		if (first)
			write(1, " ", 1);
		start = rskip_word(str, i); // ha valore di spazio prima di parola
		write(1, &str[start + 1], i - start); // Di tt str stampa da start + 1 per esattamente i - start caratteri (ultimo carattere parola - spazio prima di parola = lunghezza parola)
		i = start; // Faccio ripartire dallo spazio prima
		first = 1; // Da ora in poi se first = 1 si stampano gli spazi t
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		ft_rev_wstr(av[1]);
	return (0);
}
