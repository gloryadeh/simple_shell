#include "shell.h"

/**
 * run_builtin - checks for and runs builtin functions
 * @builtin: array of builtin functions
 * @argument: av[0]
 * Return: 0 on success
 */
int run_builtin(built_in builtin[], char *argument)
{
	int i = 0;

	/* iterate through builtin struct to check builtin functions */
	for (i = 0; builtin[i].argument != NULL; i++)
	{
		if (_strcmp(builtin[i].argument, argument) == 0)
		{
			builtin[i].function();
			return (0);
		}
	}

	return (-1);
}
