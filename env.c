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

/**
 * _setenv - calls setenv function
 * @args: pointer to arguments
 */
void _setenv(char ***args)
{
	char **av = *args;
	char *error1 = "Incomplete arguments to setenv\nsyntax: setenv VARIABLE VALUE\n";
	char *error2 = "Unable to set environment variable";
	int ret;

	if (!av[1] || !av[2])
	{
		write(2, error1, _strlen(error1));
		return;
	}

	if ((ret = setenv(av[1], av[2], 1) != 0))
	{
		write(2, error2, _strlen(error2));
		return;
	}
}

/**
 * _unsetenv - calls unsetenv
 * @args: pointer to arguments
 */
void _unsetenv(char ***args)
{
	char **av = *args;
	char *error1 = "Incomplete arguments to unsetenv\nsyntax: unsetenv VARIABLE\n";
	char *error2 = "Unable to unset environment variable";
	int ret;

	if (!av[1])
	{
		write(2, error1, _strlen(error1));
		return;
	}

	if ((ret = unsetenv(av[1]) != 0))
	{
		write(2, error2, _strlen(error2));
		return;
	}
}
