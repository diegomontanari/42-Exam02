#include <unistd.h>

void	skip_spaces(int *ptr_i, char *str) // Dato che ogni indirizzo di mem. è un puntatore al valore, passare &i richiede che nell'argomento della funzione ci sia int *ptr_i, perché mandi l'indirizzo, ti aspetti il puntatore. Questo è il modo corretto di fare passaggi per riferimento e non per valore
{
	while ((str[*ptr_i] == ' ') || ((str[*ptr_i] >= 9 && str[*ptr_i] <= 13))) // Il backspace, carattere ascii 8, non cancella, semplicemente porta indietro il cursore, non è uno spazio
		(*ptr_i)++; // Serve la parentesi perché * ha precedenza minore di ++
}

int	last(int i, char *str) // Last può lavorare con una copia di i, perché serve solo a verificare se sia effettivamente l'ultima parola, in ogni caso, non dobbiamo spostare str[i] (stesso discorso vale per str, basta una copia e quindi un passaggio per valore)
{
	while ((str[i] == ' ') || ((str[i] >= 9 && str[i] <= 13))) // Semplicemente salta gli spazi. Note: prima avevo messo " " al posto di ' ' che non va bene perché compari un char (str[i] con un pointer (" "). Il compilatore di conseguenza si lamenta.
                i++;
	if (str[i + 1] == '\0') // Se il carattere successivo è di terminazione
		return 1;
	else
		return 0;
}


void    ft_parser(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		if ((i == 0) || (last(i, str))) // Se è la prima parola o l'ultima
		{
			if ((str[i] == ' ') || ((str[i] >= 9 && str[i] <= 13))) // Se la prima o l'ultima parola iniziano con uno spazio (aggiunto questo if perché prima mi saltava la prima lettera se iniziava senza spazio)
			{
				skip_spaces(&i, str);
			}
		}
		if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)) // Se è spazio
		{
			if (!last(i, str)) // Invio una copia (passaggio per valore) di i
				{
					write(1, " ", 1);
					skip_spaces(&i, str); // Passo l'indirizzo per riferimento (dato che in skip_spaces i diventerebbe un ptr e causerebbe confusione, lo chiamo ptr_i per chiarezza anziché i)
				}
			else
				return ; // Questo non è return 0, né return NULL. Significa esci dalla funzione senza restituire nulla. Quindi può esserci in un void
		}
		if ((str[i] >= 33) && (str[i] <= 126)) // Se è un char
		{
			write(1, &str[i], 1); // write richiede un buffer
			i++; // Passo al char successivo
		}

	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_parser(av[1]);
	write(1, "\n", 1);	
}
