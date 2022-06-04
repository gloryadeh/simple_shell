#include "shell.h"

/**
 * main - simple shell
 * Return: 0 on success
 */
int main(void)
{
	/* declare variables buffer to store string, bufsize */
	char *buffer, **av;
	size_t bufsize = 32;
	ssize_t characters;

	/* allocate space for string */
	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
	{
		perror("Error: ");
		exit(98);
	}

	do
	{
		/* print "$ " */
		print_string(buffer);
		_putchar('$');
		_putchar(' ');
	} while ((characters = getline(&buffer, &bufsize, stdin)) >= 0 );

	_putchar('\n');
	free(buffer);
	return (0);
}
