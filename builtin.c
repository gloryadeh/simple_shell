#include "shell.h"

/**
 * run_builtin - checks for and runs builtin functions
 * @args: av
 * Return: 0 on success
 */
int run_builtin(char ***args)
{
	int i = 0;
	char **arguments = *args;
	built_in builtin[] = {
		{"exit", exit_prog},
		{"env", print_env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", change_dir},
		{"pwd", print_cwd},
		{NULL, NULL}
	};

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
