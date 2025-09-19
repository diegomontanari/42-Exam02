#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;

    while (*begin_list != NULL) // Finché esiste un ptr a nodo
    {
        if (cmp((*begin_list)->data, data_ref) == 0) // se i due ptr data sono uguali (nodo da eliminare)
        {
            temp = *begin_list;                  // salvo il nodo
            *begin_list = (*begin_list)->next;   // salto al successivo
            free(temp);                          // libero il nodo
        }
        else
        {
            begin_list = &(*begin_list)->next;   // avanzo col puntatore
        }
    }
}

/*
LA REGOLA D'ORO:

* → scendi di un livello: se hai un puntatore, dereferenziarlo ti dà “l’oggetto a cui punta”.
& → sali di un livello: se hai un oggetto (o un puntatore), con & ottieni “l’indirizzo di quell’oggetto”.

Non c’è simmetria automatica: non puoi “risalire” con *, perché * fa l’operazione opposta — ti porta dentro, non indietro.
Per questo motivo usiamo: begin_list = &(*begin_list)->next;

Ma NON possiamo fare: begin_list = *(*begin_list)->next;
perché (*begin_list)->next è già un t_list*, e con un altro * cercheresti di dereferenziare un nodo (t_list),
che non è un puntatore. Quindi non puoi deferenziarlo "scendere di livello", non è un puntatore.
*/
