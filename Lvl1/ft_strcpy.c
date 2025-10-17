// #include <string.h>
// #include <stdio.h>

// Copia tutto incluso terminatore stringa
char    *ft_strcpy(char *s1, char *s2) // s1 è dest, s2 è src
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return s1;
}
/*
int	main()
{
	char dest[250];
	ft_strcpy(dest, "Ciao");
	printf("s1: %s\n", dest);
	return 0;
}
*/
