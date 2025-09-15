#include "ft_list.h" // Le virgolette significano che il compilatore cerca in locale, se non trova cerca nelle librerie di sistema come se fosse < >

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
  while (begin_list) // Finché non arrivi alla fine della lista
  {
    (*f)(begin_list->data); // This line applies the function to the data. IMPORTANT: f(data) and (*f)(data) are EQUIVALENT in C—they do exactly the same thing.
    begin_list = begin_list->next; // // Vai al prossimo nodo
  }
}

