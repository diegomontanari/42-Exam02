// #include <stdio.h>
#include <stddef.h>  // per size_t è necessaria (ricorda)

size_t  ft_strcspn(const char *s, const char *reject)
{
	size_t len_min = 0;
	size_t i = 0;
	size_t j = 0;

	while (s[len_min])
		len_min++; // Così len min parte dal massimo (ovvero non match)
	
	while (reject[i]) // Finché esiste reject
	{
		while (s[j] && s[j] != reject[i]) // Finché esiste s e non combacia char
			j++;
		
		if (j <= len_min) // Se troviamo un match prima di len_min
			len_min = j; // Salvo la lunghezza della sequenza minore (ricorda: con cosa sto lavorando? Con due size_t , allora ok)
		
		j = 0; // Resettiamo per ripartire dall'inizio di s
		i++; // Passo al successivo char di reject
	}
	return len_min;
/*
}

int	main()
{
	const char *s = "Ciao Provolone"; 
	const char *reject = "rovn";
	
	size_t test1 = ft_strcspn(s,reject);
	printf("%zu", test1); // Non ricordavo che fosse %zu il placeholder di size_t
	return 0;
}
*/
