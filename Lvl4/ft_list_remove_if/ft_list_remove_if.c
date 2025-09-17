#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list **curr = begin_list // curr = &begin_list
	t_list temp;

	while (*curr) // Scorro i nodi (*curr is a node, curr is a &, and **curr does not exist, since a node is not a pointer)
	{
		if (*cmp((*curr)->data,data_ref) == 0) // Se il campo data del nodo è corrispondente al segnale
		{
 	        	temp = *curr;               // salvo il nodo da eliminare
            		*curr = (*curr)->next;      // aggiorno il link che lo puntava
            		free(temp);                 // libero il nodo
        	}
        	else
        	{
        		curr = &(*curr)->next;      // sposto curr al "link successivo"
        	}
    	}
}
