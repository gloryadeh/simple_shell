#include "shell.h"

/**
 * execute - creates a child process and executes a command
 * @av: array of argument strings
 */
void execute(char **av)
{
	int status, builtin_stat;
	struct stat st;
	pid_t child_pid;
	built_in builtin[] = {
		{"exit", exit_prog},
		{"env", print_env},
		{NULL, NULL}
	};

	/* check for ls and change to /bin/ls */
	if (_strcmp(av[0], "ls") == 0)
		rename_ls(&av);
	/* check if the command exists */
	if (stat(av[0], &st) == 0)
		child_pid = fork();
	else if (stat(av[0], &st) == -1)
	{
		builtin_stat = run_builtin(builtin, av[0]);
		if (builtin_stat != 0)
			return;
	}

	/* check if we are in parent or child process */
	if (child_pid == 0)
	{
		/* we are in the child process */
		if (execve(av[0], av, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		/* we are in parent process, */
		/* child process is still running so we are waiting for it */
		wait(&status);
	}
	/* if command doesn't exist*/
	else
		return;
}
