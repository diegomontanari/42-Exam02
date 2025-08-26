#include "flood_fill.h"

/*
** Funzione ricorsiva di riempimento.
** cur: punto corrente
** to_fill: carattere di riferimento da sostituire
*/
static void	fill(char **tab, t_point size, t_point cur, char to_fill) // In flood_fill è begin, ma qui lo chiamo cur perché viene sostituito con il progresso del riempimento
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
	// (t_point){cur.x + 1, cur.y} is a compound literal, which is a quick way to create a temporary t_point without declaring an intermediate variable.
	// If you don’t want to use a compound literal, you would first declare a temporary t_point variable for each direction and then pass it to the function. For example:
	/*  t_point right = {cur.x + 1, cur.y};
		fill(tab, size, right, to_fill);

		t_point down = {cur.x, cur.y + 1};
		fill(tab, size, down, to_fill);

  	*/
	// And so on... This is exactly the same, but requires the double amount of lines.
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
