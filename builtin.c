#include "shell.h"

/**
 * run_builtin - checks for and runs builtin functions
 * @builtin: array of builtin functions
 * @args: av
 * Return: 0 on success
 */
int run_builtin(built_in builtin[], char ***args)
{
	int i = 0;
	char **arguments = *args;

	/* iterate through builtin struct to check builtin functions */
	for (i = 0; builtin[i].argument != NULL; i++)
	{
		if (_strcmp(builtin[i].argument, arguments[0]) == 0)
		{
			builtin[i].function(args);
			return (0);
		}
	}

	return (-1);
}
