/*
** Scambia i 4 bit più alti con i 4 bit più bassi in un `unsigned char`.
**
** - `octet >> 4` sposta i 4 bit alti verso destra (diventano i 4 bit bassi).
** - `octet << 4` sposta i 4 bit bassi verso sinistra (diventano i 4 bit alti).
** - L'OR bit a bit combina i due risultati, effettuando lo scambio. Fantastico!
*/
unsigned char swap_bits(unsigned char octet)
{
    return((octet >> 4) | (octet << 4));
}

/*
Esempio:
octet = 01000001     (65 in decimale)
octet >> 4 = 00000100
octet << 4 = 00010000
return 00010100     (20 in decimale)

*/