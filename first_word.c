#include <unistd.h>

void  print_1st_word(char *str)
{
  int  i;
  
  i = 0;
    // Salta spazi e tab
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Stampa fino al prossimo spazio/tab o fine stringa
    while (str[i] && str[i] != ' ' && str[i] != '\t')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int  main(int argc, char **argv)
{
  if (argc == 2)
    print_1st_word(argv[1]);
  write(1, "\n", 1);
	return (0);
}
