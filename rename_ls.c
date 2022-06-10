#include "shell.h"

/**
 * rename_ls - renames ls to /bin/ls
 * @args: pointer to arguments
 */
void rename_ls(char ***args)
{
	char **av = *args;
	char *string = "/bin/ls";
	int i;

	for (i = 0; string[i]; i++)
		av[0][i] = string[i];
	av[0][i] = '\0';
}
