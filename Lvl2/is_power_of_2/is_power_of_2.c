/*
** Verifica se il numero `n` è una potenza di 2.
**
** RICORDA TRUCCO MATEMATICO: Una potenza di 2 in binario ha esattamente un solo bit impostato a 1.
** Esempi: 
**   1  = 00000001
**   2  = 00000010
**   4  = 00000100
**   8  = 00001000
**
** La condizione '(n > 0 && (n & (n - 1)) == 0)' è vera solo per le potenze di 2:
** --> `n > 0` esclude il caso speciale di `0`, che non è potenza di 2.
** --> 'n & (n - 1)' confronta tutti i bit di n e di n - 1 (vedi operatori bitwise)
** 
** Esempio 1: se n = 4, n in binario = 100, allora n - 1 in binario = 011. & restituisce 000, quindi 000 == 0, quindi True -> 4 è potenza di 2.
** Esempio 2: n = 6 = 110 in binario, allora n - 1 = 101. & ridà 100, quindi 100 == 0, False -> 6 non è potenza di 2.
** 
** Ritorna:
** - 1 (True) se `n` è potenza di 2
** - 0 (False) altrimenti
*/
int is_power_of_2(unsigned int n)
{
    return(n > 0 && (n & (n - 1)) == 0);
}

/* 
Non ti ricordi questo ragionamento? Nessun problema, lo fai così:

int         is_power_of_2(unsigned int n)
{
        unsigned int p = 2;

        if (n <= 0)
                return 0;
        if (n == 1)
                return 1;
        while (n != p)
        {
                if (n % p == 0)
                        n /= p;
                else
                        return 0;
        }
}

(Implementazione in stile fprime)
*/
