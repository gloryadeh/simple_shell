#include "shell.h"

/**
 * execute - creates a child process and executes a command
 * @args: array of argument strings
 */
void execute(char **args)
{
	int status;
	struct stat st;
	pid_t child_pid;

	/* check if the command exists */
	if (stat(args[0], &st) == 0)
		child_pid = fork();
	else
		return;

	if (child_pid == 0)
	{
		/* we are in the child process */
		if (execve(args[0], args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		/* we are in parent process, */
		/* child process is still running so we are waiting for it */
		wait(&status);
	}
	else
	{
		/* if execve returns*/
		exit(EXIT_FAILURE);
	}
}
