#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
        int a = atoi(argv[1]);     // converts the first argument to an integer
        char c = argv[2][0];       // extracts the first character of the operator
        int b = atoi(argv[3]);     // converts the third argument to an integer

		if (c == '+')
			printf("%d\n", a + b);
		else if (c == '-')
			printf("%d\n", a - b);
		else if (c == '*')
			printf("%d\n", a * b);
		else if (c == '/')
			printf("%d\n", a / b);
		else if (c == '%')
			printf("%d\n", a % b);
	}
	else
		printf("\n");

	return 0;
}