#include "shell.h"

/**
 * execute - creates a child process and executes a command
 * @args: array of argument strings
 */
void execute(char **args)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		/* we are in the child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		/* we are in parent process, */
		/* child process is still running so we are waiting for it */
		wait(&status);
	}
	else
	{
		/* if execve returns */
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
}
