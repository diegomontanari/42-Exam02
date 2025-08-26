#include "flood_fill.h"

/*
** Funzione ricorsiva di riempimento.
** cur: punto corrente
** to_fill: carattere di riferimento da sostituire
*/
static void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	// 1. Controllo dei limiti (se esco dall'array, termino subito)
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
		return;

	// 2. Se il carattere NON è quello che devo riempire, termino
	if (tab[cur.y][cur.x] != to_fill)
		return;

	// 3. Sostituisco il carattere con 'F'
	tab[cur.y][cur.x] = 'F';

	// 4. Chiamate ricorsive nelle 4 direzioni
	//    (destra, sinistra, giù, su)
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

/*
** Funzione principale:
** - Recupera il carattere di partenza (da begin)
** - Avvia la funzione ricorsiva
*/
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char to_fill;

	to_fill = tab[begin.y][begin.x];  // il carattere da sostituire
	fill(tab, size, begin, to_fill);
}

