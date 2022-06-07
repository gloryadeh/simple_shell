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

	while (characters != EOF)
	{
		/* print "$ " */
		_putchar('$');
		_putchar(' ');

		/* allocate space for string */
		buffer = malloc(sizeof(char) * buffsize);
		if (buffer == NULL)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}

		/* get characters */
		characters = getline(&buffer, &buffsize, stdin);

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

		/* execute command */
		execute(av);

		/* free array */
		for (i = 0; i <= len; i++)
			free(av[i]);
		free(av);
		free(buffer);
	}

	_putchar('\n');
	return (0);
}
