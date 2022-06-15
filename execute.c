#include "shell.h"

/**
 * execute - creates a child process and executes a command
 * @av: array of argument strings
 * @argv: argument variables
 */
void execute(char **av, char **argv)
{
	int status, builtin_stat;
	struct stat st;
	pid_t child_pid = -1;

	if (_strcmp(av[0], "ls") == 0) /* check for ls */
		rename_ls(&av); /* rename ls to /bin/ls */

	if (stat(av[0], &st) == 0) /* check if the command exists */
		child_pid = fork(); /* create child process */
	else if (stat(av[0], &st) == -1) /* if command doesn't exist */
	{
		builtin_stat = run_builtin(&av);
		if (builtin_stat != 0)
		{
			write(2, argv[0], _strlen(argv[0])), write(2, ": ", 2);
			write(2, "No such file or directory\n", 26);
			return;
		}
	}
	/* check if we are in parent or child process */
	if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1) /* we are in the child process */
			exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		/* parent process, child process is running, we are waiting for it */
		wait(&status);
	}
	else
		return;
}
