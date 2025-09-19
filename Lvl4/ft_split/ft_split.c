

int	is_delimiter(char c)
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

int ft_wordlen(char *str)
{
	int i = 0;
	while (str[i] && !is_delimiter(str[i]))
		i++;
	return i;
}

int word_count(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		i = skip_space(str, i);
		if (str[i] && !is_delimiter(str[i]))
		{
			count++;
			i = skip_word(str, i);
		}
	}
	return count;
}

// Prende in input una parola, la alloca come str separata e la ritorna
char *word_dup(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return NULL;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return new;
}

char **ft_split(char *str)
{
	int i = 0;
	int total = word_count(str); // Conta parole totali
	int j = 0;
	char **array = malloc(sizeof(char *) * (total + 1)); // Alloco l'array di array di char (misura total + spazio per puntatore NULL)
// Proprio come le stringhe terminano con '\0', gli array di stringhe come buona pratica terminano con un puntatore NULL
	if (!array)
		return NULL;

	while (str[i])
	{
		i = skip_space(str, i); // Primo carattere non delimitatore (ma attento non è detto che sia una parola)
		if (str[i] && !is_delimiter(str[i])) // Se true, hai trovato l'inizio di una parola
		{
			array[j++] = word_dup(&str[i]); // Copia la parola in un "mini" array che viene inserito nella posizione j di array "grande"
			i = skip_word(str, i);
		}
	}
	array[j] = NULL; // Imposto l'ultimo j come NULL
	return array;
}
