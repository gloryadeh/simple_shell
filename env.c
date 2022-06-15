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
 * _callsetenv - calls setenv function
 * @args: pointer to arguments
 */
void _callsetenv(char ***args)
{
	char **av = *args;
	char *error1 = "Error:\n\tsyntax: setenv VARIABLE VALUE\n";
	char *error2 = "Unable to set environment variable";
	int ret;

	if (!av[1] || !av[2])
	{
		write(2, error1, _strlen(error1));
		return;
	}

	ret = _setenv(av[1], av[2], 1);
	if (ret != 0)
	{
		write(2, error2, _strlen(error2));
		return;
	}
}

/**
 * _callunsetenv - calls unsetenv
 * @args: pointer to arguments
 */
void _callunsetenv(char ***args)
{
	char **av = *args;
	char *error1 = "Error:\n\tsyntax: unsetenv VARIABLE\n";
	char *error2 = "Unable to unset environment variable";
	int ret;

	if (!av[1])
	{
		write(2, error1, _strlen(error1));
		return;
	}

	ret = unsetenv(av[1]);
	if (ret != 0)
	{
		write(2, error2, _strlen(error2));
		return;
	}
}
