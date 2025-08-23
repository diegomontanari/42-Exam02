/*
HEADER GUARD:

#include "qualcosa.h" inserisce tutto il contenuto di qualcosa.h nel file .c
finché includi in un solo file va bene. Ma se includi in più di un file (quindi vari #include "qualcosa.h" in vari file)  il compiler da errore.
allora bisogna aggiungere un'header guard.

L'header guard è strutturata così:

#ifnotdef QUALCOSA_H 
#define QUALCOSA_H
--il contenuto
#endif

il nome in maiuscolo è una convenzione e non deve essere uguale al file, ma è meglio che sia simile.

Grazie all'header guard, il compilatore vede l'include (#include "qualcosa.h") lo definisce come QUALCOSA_H e se lo rivede, grazie alla guard, LO SALTA senza dare errori, tanto è già stato definito.

Chiaro.
*/


typedef struct    s_list
{
    struct s_list *next; // Puntatore a elem. successivo di tipo s_list della lista
    void          *data; // Il puntatore al contenuto di ogni nodo
}                 t_list; // Alias: anziché struct s_list ogni volta posso scrivere t_list
