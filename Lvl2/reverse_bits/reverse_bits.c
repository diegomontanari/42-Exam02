/*
reversed << 1: 
-> Shifts all bits of reversed one position to the left (like multiplying by 2). 
-> This creates space for the new bit (a zero enters by default on the right, still 8 bits in total of)

octet & 1:
-> Extracts the least significant bit (the rightmost one) of octet.

|: 
-> Adds that bit to reversed using a bitwise OR.

octet >>= 1: 
-> Shifts octet one position to the right, so the next bit is ready for the next loop iteration.

Essentially, you're reading the bits of octet from right to left and
writing them into reversed from left to right.
*/
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char reversed = 0; // Inizio con tutti i bit a 0

	for (int i = 8; i > 0; i--)
		reversed = (reversed << 1) | (octet & 1), octet >>= 1;

	return reversed;
}

/*
Step by step example:

ITERATION 1:
-> Let's start from octect = 4 (00000100)

-> reversed << 1 shifts everything one place to the left, creating
   one free space on the right (0 * 2 = 0)

-> octect & 1 takes the LSF of octect (0) and returns a byte with
   only the LSF


-> The bitwise OR compares reversed 00000000 and octect 00000100

-> now this result (00000100) is assigned to reversed

-> >>= assignes the new shifted value (00001000) to octet (4 * 2 is 8)

reversed = 00000000
octet = 00001000 (This is 8 in decimal, indeed 4 * 2)

ITERATION 2:

-> We start from octect = 8 (00001000)

-> reversed is still 00000000 (0 * 2)

octet & 1 → 


*/