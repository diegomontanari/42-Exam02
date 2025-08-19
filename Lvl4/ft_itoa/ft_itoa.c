#include <unistd.h>
#include <stdlib.h>

/*
** Calcola la lunghezza necessaria per convertire `n` in stringa.
** - Se `n < 0`, include 1 per il segno '-'.
** - Conta le cifre in base 10.
** - Caso particolare: `n == 0` → lunghezza 1 (gestito in ft_itoa).
*/
int get_len(int n)
{
    int len = 0;

    if (n <= 0)
        len++;  // per '0' o '-'
    while (n != 0)
    {
        len++;
        n = n / 10;
    }
    return len;
}

/*
** Converte un intero `nbr` in una stringa allocata dinamicamente.
**
** - Usa `long long` per gestire il caso `-2147483648` senza overflow.
** - Alloca una stringa con dimensione calcolata da `get_len`.
** - Inserisce il terminatore `\0` alla fine.
** - Gestisce zero e numeri negativi.
** - Inserisce le cifre da destra a sinistra.
**
** Ritorna:
** - Puntatore alla stringa allocata
** - NULL in caso di errore malloc
**
** Esempio:
** ft_itoa(-123) → "-123"
** ft_itoa(0)    → "0"
*/
char *ft_itoa(int nbr)
{
    int len = get_len(nbr);
    long long n = nbr; // Converto per essere più sicuro nei casi limite
    char *result = malloc(len + 1);
    if (!result)
        return NULL;
    result[len] = '\0'; // Add '\0' at the end. Gli indici partono da 0, len da 1, quindi ovviamente len accede a un posto dopo la fine (perché sfalsato di uno a destra) mi dimentico sempre di questo semplice dettaglio e ci metto un paio di secondi a rendermene conto.
    if (n == 0)
        result[0] = '0';
    if (n < 0)
    {
        result[0] = '-';
        n = -n; // Cambio segno per farlo tornare positivo ed estrarre nel secondo while
    }
    while (n != 0)
    {
        result[--len] = n % 10 + '0'; // Parto da destra, il modulo di 10 prende l'ultima cifra, + '0' converte in ASCII (es: 2 = 50, 0 = 48, quindi 50 - 48 = 2)
        n = n / 10; // Serve solo ad arrivare all'uscita dal while (es: 50 / 10, 5 / 10 esce dal while, quindi 2 cicli quindi 2 caratteri stampati)
    }
    return result;
}

/*
** // Test:
** #include <stdio.h>
**
** int main()
** {
**     printf("%s\n", ft_itoa(-2147483648));
**     printf("%s\n", ft_itoa(0));
**     printf("%s\n", ft_itoa(12345));
**     return 0;
** }
*/
