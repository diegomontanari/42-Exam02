#include <unistd.h>

/*
REMEMBER:
-> Every byte is made of 8 bits

EXAMPLE:
-> 14 in binary is 1110
-> So 14 in bits (as a full byte) will be 00001110

NOTE:
-> With 1 byte I can represent 256 distinct numerical values (because 2 ** 8 = 256)
-> An unsigned char uses exactly 1 byte and can represent numerical values from 0 to 255
-> A signed char also uses 1 byte, but represents values from -128 to +127
   (because half of the combinations are used for negative numbers)
-> In conclusion, working with an unsigned char means working directly with a raw byte,
   which is ideal for bit-level operations like print_bits.
*/

void	print_bits(unsigned char octet)
{
	for (int i = 7; i >= 0; i--)
	{
		if ((octet >> i) & 1) // & 1 isolates the least significant bit (& (AND Operator) != && (Logical AND))
			write(1, "1", 1); // >> i shifts the bits to the right by i positions (logical shift)
		else
			write(1, "0", 1);
	}
}

/*
ONE LAST NOTE:
-> Using (octet >> i) creates a new shifted value, but does NOT modify the original 'octet' (so we can use it)
-> Using (octet >>= i) actually changes 'octet' and permanently discards the shifted-out bits
*/
