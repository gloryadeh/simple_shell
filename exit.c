#include "shell.h"

/**
 * exit_prog - runs when user types exit
 * @args: pointer to arguments
 */
void exit_prog(char ***args)
{
	char **arguments = *args;
	int number;

	if (arguments[1]) /* if exit is given an argument */
	{
		number = _atoi(arguments[1]); /* convert it to an integer */
		exit(number); /* call exit */
	}
	else
		exit(EXIT_SUCCESS);
}
