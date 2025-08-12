/*
** Verifica se il numero `n` è una potenza di 2.
**
** Una potenza di 2 in binario ha esattamente un solo bit impostato a 1.
** Esempi: 
**   1  = 00000001
**   2  = 00000010
**   4  = 00000100
**   8  = 00001000
**
** La condizione `(n & (n - 1)) == 0` è vera solo per le potenze di 2:
** - `n - 1` ha tutti i bit a 1 dopo il bit più significativo di `n`
** - L'AND azzera tutto se e solo se `n` aveva un solo bit attivo
**
** Inoltre, `n > 0` esclude il caso speciale di `0`, che non è potenza di 2.
**
** Ritorna:
** - 1 se `n` è potenza di 2
** - 0 altrimenti
*/
int is_power_of_2(unsigned int n)
{
    return(n > 0 && (n & (n - 1)) == 0);
}
