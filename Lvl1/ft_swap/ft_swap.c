void	ft_swap(int *a, int *b)
{
	int temp;
	
	temp = *a; // Assegno *a a temp
	*a = *b; // *a diventa *b
	*b = temp; // *b diventa *a
}