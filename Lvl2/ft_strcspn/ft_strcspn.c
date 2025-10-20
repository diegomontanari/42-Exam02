#include <stddef.h> // libreria pensata per È pensato per fornire tipi portabili e sicuri (tipo NULL, size_t ecc) (ma spesso sono ridefiniti in altre lib quindi non serve spesso dichiarare stddef.h)
// #include <string.h>
// #include <stdio.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
        size_t len = 0;

        size_t i = 0; // su input molto lunghi usare int avrebbe dato problemi (perché è signed) mentre size_t ha un range molto più grande, meglio usare size_t (ma parliamo di nuemri enormi) 
        size_t j = 0;

        while (s[i])
        {
                while (reject[j])
                {
                        if (s[i] == reject[j])
                                return len;
                        else
                                j++;
                }
                len++;
                j = 0;
                i++;
        }
        return len;
}


/*
int     main()
{
        const char s1[] = "ABBACABC";
        const char s2[] = "CE";
        
        printf("testmio:%zu\n", ft_strcspn(s1, s2));
        printf("testsuo:%zu\n", strcspn(s1, s2));
        
        return 0;
}
*/

/* 
NOTA CHE NON SAPEVO:

Hai centrato una questione sottile ma importante, Diego. La risposta è: non è definito direttamente in string.h, ma può essere reso disponibile attraverso di esso. Ti spiego perché.

🧩 Come funziona davvero:

size_t è formalmente definito in stddef.h, che è l’header standard per i tipi fondamentali.

Tuttavia, molti altri header — come string.h, stdlib.h, stdio.h — includono stddef.h internamente, oppure includono altri header che a loro volta lo includono.

Quindi, quando includi string.h, il compilatore ha già accesso alla definizione di size_t, anche se non è scritta direttamente lì.

📘 Analogia didattica: Immagina stddef.h come una scatola di attrezzi base. Altri header come string.h sono come kit specializzati (per le stringhe, per la memoria, ecc.) che portano con sé quella scatola base, anche se non te lo dicono esplicitamente.

🔍 Verifica pratica: Se scrivi:

c
#include <string.h>

size_t len = strlen("Diego");
Funziona perfettamente, perché size_t è disponibile grazie all’inclusione transitiva di stddef.h.

🧠 Conclusione:

Se vuoi sapere dove è definito ufficialmente, la risposta è stddef.h.

Se vuoi sapere perché puoi usarlo anche con string.h, è perché string.h lo include indirettamente.
*/

