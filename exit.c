#include "shell.h"

/**
 * call_cd - calls the cd function and frees OLDWD
 */
void call_cd(void)
{
	char **exit_cd;
	char *exit_text = "exit", *cd = "cd";
	int i;

	exit_cd = malloc(sizeof(char *) * 100);
	if (exit_cd == NULL)
		exit(EXIT_FAILURE);

	exit_cd[0] = malloc(sizeof(char) * 3);
	if (exit_cd[0] == NULL)
		exit(EXIT_FAILURE);
	_strcpy(exit_cd[0], cd);

	exit_cd[1] = malloc(sizeof(char) * 5);
	if (exit_cd[1] == NULL)
		exit(EXIT_FAILURE);
	_strcpy(exit_cd[1], exit_text);

	exit_cd[2] = NULL;


	change_dir(&exit_cd);
	for (i = 0; exit_cd[i]; i++)
		free(exit_cd[i]);
	free(exit_cd);
}

/**
 * exit_prog - runs when user types exit
 * @args: pointer to arguments
 */
void exit_prog(char ***args)
{
	char **arguments = *args;
	int number, i;

	if (arguments[1]) /* if exit is given an argument */
	{
		number = _atoi(arguments[1]); /* convert it to an integer */

		for (i = 0; arguments[i]; i++) /* free arguments */
			free(arguments[i]);
		free(arguments);
		call_cd(); /* free OLDWD */
		exit(number); /* call exit */
	}
	else
	{
		for (i = 0; arguments[i]; i++) /* free arguments */
			free(arguments[i]);
		free(arguments);
		call_cd(); /* free OLDWD */
		exit(EXIT_SUCCESS);
	}
}
