#include "sort_list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *start = lst;        // Salvo il puntatore all'inizio della lista per ripartire dall'inizio ogni volta (tipo i = 0 in sort_int_tab)
	int temp;                   // Variabile temporanea per scambiare i valori

	while (lst != NULL && lst->next != NULL)  // Finché ci sono almeno due nodi da confrontare
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)  // Se la coppia è fuori ordine
		{
			temp = lst->data;               // Salvo il valore del nodo corrente
			lst->data = lst->next->data;    // Copio il valore del nodo successivo nel nodo corrente
			lst->next->data = temp;         // Metto il valore salvato nel nodo successivo (swap completato)
			lst = start;                     // Riparto dall'inizio della lista dopo lo scambio
		}
		else
			lst = lst->next;                // Altrimenti passo al nodo successivo
	}
	return start;                          // Ritorno il puntatore all'inizio della lista ordinata
}
