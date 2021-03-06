#include "shell.h"

/**
 * main - simple shell
 * Return: 0 on success
 * @argc: argument count
 * @argv: argument variables
 */
int main(__attribute__ ((unused)) int argc, char **argv)
{
	/* declare variables */
	char *buffer, **av;
	size_t buffsize = 1024;
	int i, len = 0;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2); /* print '$ ' */
		/* allocate space for string */
		buffer = malloc(sizeof(char) * buffsize);
		if (buffer == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		/* get characters and check for EOF */
		_getline(&buffer);
		if (buffer[0] == EOF)
		{
			free(buffer);
			break;
		}
		rem_line(&buffer);	/* remove trailing new line */
		av = split_string(buffer, " "); /* split string into av */
		free(buffer);
		len = len_av(av); /* get length of av */
		execute(av, argv);	/* execute command */
		for (i = 0; i <= len; i++) /* free array */
			free(av[i]);
		free(av);
	}
	return (0);
}
