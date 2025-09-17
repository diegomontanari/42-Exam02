#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list **curr = begin_list; // Initially points to begin_list, then will "look" at the next nodes
    t_list *temp;

    while (*curr) // Traverse the list (*curr is the current node, curr is a pointer to the pointer that points to it)
    {
        if ((*cmp)((*curr)->data, data_ref) == 0) // If the node's data matches data_ref
        {
            temp = *curr;               // Save the node to delete
            *curr = (*curr)->next;      // Update the previous pointer to skip over the node (-> has precedence over *)
            free(temp);                 // Free the removed node
        }
        else
        {
            curr = &(*curr)->next;      // Move curr to point to the address of the next node's pointer
                                         // Note: curr itself does not modify the list, it only observes the pointers
                                         // *curr is the current node, &(*curr)->next moves the "observer" to the next node's link
        }
    }
}

/*
This implementation uses a pointer to a pointer. Why?

Because it allows us to handle node removal uniformly, including the head of the list, 
without needing a special case or a separate "previous" pointer. 
By using a pointer to a pointer, we can update the links directly while traversing the list.

How it works:

- curr points to the pointer that points to the current node (it observes the links).
- *curr is the current node.
- When we remove a node, *curr is updated to skip over it, effectively modifying the list.
- When we just move forward (curr = &(*curr)->next), curr moves to the next pointer in the list 
  without modifying the nodes themselves. It’s like moving a finger along the "next" fields 
  of the nodes: the nodes remain untouched, and curr always has the ability to modify links if needed.

This is a more elegant approach, as only one while loop is used. 
But there are others: longer, less elegant, but easier to understand.
Like this one:

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;

    // Rimozione dei nodi all'inizio della lista
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp);
    }

    // Rimozione dei nodi interni
    t_list *curr = *begin_list;
    while (curr && curr->next)
    {
        if (cmp(curr->next->data, data_ref) == 0)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else
            curr = curr->next;
    }
}

What is the real difference? 
- In the first version (pointer-to-pointer), curr acts like a “pointer observer”: it follows the 
  links of the list without touching the nodes themselves, and can modify any link when needed. 
  This allows a single loop to handle both the head and internal nodes uniformly. 
  You never need a separate "previous" pointer, because the observer always sees the pointer 
  that points to the current node.

- In the second version, we “hand over control” from the observer to a single pointer. 
  We first handle the head nodes explicitly, then use a regular pointer to walk the rest of the list. 
  Here, the pointer itself is responsible for moving through the nodes and updating links, 
  which is conceptually simpler but requires separate handling of the head and internal nodes.

In other words:
- Pointer-to-pointer = you keep the “observer” that can manipulate links anywhere, elegant and uniform.
- Single-pointer version = you stop using the observer, walk the nodes directly, explicit but more verbose.
Both work, but the first version is like having a tool that can always reach the next connection, 
while the second version makes you manually reach each connection one by one.
*/

