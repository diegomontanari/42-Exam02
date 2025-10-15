// I've used a less optimized Bubble Sort:

// A classic Bubble Sort performs multiple full passes over the array, keeping track of whether any swaps occurred during each pass.

// In this version, every time a swap happens, the algorithm restarts from the beginning, which can lead to more comparisons than necessary.

// Therefore, in terms of efficiency, this variant can be slower than a standard Bubble Sort optimized with a swapped variable.

// The only more optimized version that has a similar lenght is not accepted by 42 as it uses a for and a do while loop, so I'm gonna use this one.

/*
** - Iterates through the array comparing each adjacent pair.
** - If two elements are out of order, it swaps them.
** - After each swap, it restarts from the beginning (i = 0) to ensure full sorting.
**
** Worst-case complexity: O(n^2).
** Works correctly even with duplicate values.

*/

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int temp;
	
	while (i < size -1) // Because I start from 0 and not 1 (If i started from 1 I'd check <= , but I sill need to add -1 because I'm checking not only tab[i] but also tab[i + 1]
	{
		if (tab[i] > tab[i + 1]) // Need to swap
		{
			temp = tab[i]; // Bigger value saved in temp
			tab[i] = tab[i+1]; // Smaller value saved in tab[i] (so swapped before the bigger one)
			tab[i + 1] = temp; // Bigger value assigned after the smaller one (swap completed)
			i = 0; // restart
		}
		else // Sorted, no need to swap, I can continue checking
			i++;
	}
}




