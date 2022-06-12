#include "shell.h"

/**
 * print_env - print the environment variables
 * @args: pointer to argument variables
 */
void print_env(__attribute__ ((unused)) char ***args)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_string(environ[i]);
		_putchar('\n');
	}
}
