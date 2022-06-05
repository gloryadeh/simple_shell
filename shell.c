#include "shell.h"

/**
 * main - simple shell
 * Return: 0 on success
 */
int main(void)
{
	/* declare variables */
	char *buffer, **av;
	size_t buffsize = 32;
	ssize_t characters;
	int i, len;

	/* allocate space for string */
	buffer = malloc(sizeof(char *) * buffsize);
	if (!buffer)
	{
		perror("Error: ");
		exit(98);
	}
	/* allocate spcae for av */
	av = malloc(sizeof(char **) * 1024);
	if (!av)
	{
		perror("Error: ");
		exit(98);
	}

	do {
		/* split the string and get the length of words */
		printf("About to call split_string");
		split_string(buffer, " ", &av);
		len = len_av(av);
		/* print strings */
		for (i = 0; av[i] && len > 0; i++)
		{
			print_string(av[i]);
			if (i != len - 1)
				print_string(" ");
		}

		/* print "$ " */
		_putchar('$');
		_putchar(' ');
	} while ((characters = getline(&buffer, &buffsize, stdin)) >= 0);

	_putchar('\n');

	printf("Got here\n");
	for (i = len; i >= 0; i--)
	{
		printf("av[%d] = %s\n", i, av[i]);
		free(av[i]);
		printf("freed\n");
	}
	free(av);
	/*free(buffer);*/
	return (0);
}
