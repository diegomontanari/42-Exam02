// Converte un carattere `c` in valore numerico, compatibile con basi fino a 16.

int char_to_value(char c)
{
	if(c >= '0' && c <= '9')
		return(c - '0'); // Es: 4 ha ascii 54, 54 - '0' (48 in ascii) = 4 in int perché return value
	if(c >= 'a' && c <= 'f')
		return(c - 'a' + 10); // Identico ma per minuscole
	if(c >= 'A' && c <= 'F')
		return(c - 'A' + 10); // Identico ma per maiuscole
	return(-1); // Altri caratteri non validi (non esistono) in base 16
}

/*
Converte una stringa `str` in intero secondo la base specificata (2–16).

1. Ignora spazi iniziali e caratteri di controllo (tab, newline, ecc.).
2. Gestisce opzionalmente un segno '+' o '-' (solo come primo char valido).
3. Per ogni carattere, converte in valore numerico con `char_to_value`.

    - Se il valore è valido e inferiore alla base, lo accumula in `res`.
    - Altrimenti termina la conversione.

Ritorna l'intero risultante, tenendo conto del segno.

Esempi:
** ft_atoi_base("1010", 2)   → 10
** ft_atoi_base("1A", 16)    → 26
** ft_atoi_base("-7B", 16)   → -123
*/

int ft_atoi_base(const char *str, unsigned int base)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	int value;

	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}

	while((int)(value = char_to_value(str[i])) != -1 && value < (int)base) // Assegna a int value i vari char, controlla che il char sia valido nella base (!= -1) e che esso sia minore della base scelta (es: in base 2 un char non può essere 3, ma solo 0 o 1)
	{
		res = res * base + value; // Se il carattere divenuto int è valido, salvo res con algoritmo. Es: 124 in base 10 -> 0*10 + 1 = 1 ; 1 * 10 + 2 = 12 ; 12*10 + 4 = 124 . Facile! Algoritmo atoi base. 
		i++; // Passo al char successivo
	}
	return(res * sign); //Aggiungo il segno
}
