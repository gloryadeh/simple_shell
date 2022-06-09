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

		/* get characters and remove trailing new line */
		characters = getline(&buffer, &buffsize, stdin);
		rem_line(&buffer);
		/* split string into av and get the length of av */
		av = split_string(buffer, " ");
		len = len_av(av);

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
