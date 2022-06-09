#include "shell.h"

/**
 * print_env - print the environment variables
 */
void print_env(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_string(environ[i]);
		_putchar('\n');
	}
}
