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
	int i, len = 0;

	/* allocate space for string */
	buffer = malloc(sizeof(char) * buffsize);
	if (buffer == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	do {
		/* split string into av */
		av = split_string(buffer, " ");
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

	/* free array */
	for (i = 0; i <= len; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (0);
}
