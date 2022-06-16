#include "shell.h"

/**
 * home_dir - get home directory
 * @home: pointer to home directory string
 */
void home_dir(char **home)
{
	int i, j = 0, k = 0;
	char *homedir = *home;

	for (i = 0; environ[i]; i++) /* iterate the environment variables */
	{
		if (environ[i][k] == 'H' && environ[i][k + 1] == 'O')
		{
			k += 2;
			if (environ[i][k] == 'M' && environ[i][k + 1] == 'E')
			{
				k += 3;
				while (environ[i][k] != '\0')
				{
					homedir[j] = environ[i][k];
					k++, j++;
				}
			}
		}
	}

	homedir[j] = '\0'; /* null terminate string */
}

/**
 * _getcwd - get current workign directory
 * @cwd: pointer to string containing current working directory
 */
void _getcwd(char **cwd)
{
	char *working_dir = *cwd;
	int i, j = 0, k = 0;

	for (i = 0; environ[i]; i++) /* iterate the environment variables */
	{
		if (environ[i][k] == 'P' && environ[i][k + 1] == 'W')
		{
			k += 2;
			if (environ[i][k] == 'D')
			{
				k += 2;
				while (environ[i][k] != '\0')
				{
					working_dir[j] = environ[i][k];
					k++, j++;
				}
			}
		}
	}

	working_dir[j] = '\0'; /* null terminate string */
}

/**
 * print_cwd - print current working directory
 * @args: pointer to arguments
 */
void print_cwd(__attribute__ ((unused)) char ***args)
{
	char *cwd;

	cwd = malloc(sizeof(char) * BUF_SIZE);
	if (cwd == NULL)
		exit(EXIT_FAILURE);

	_getcwd(&cwd);

	print_string(cwd);
	_putchar('\n');
	free(cwd);
}

/**
 * change_dir - changes the current working directory of the process
 * @args: pointer to arguments
 */
void change_dir(char ***args)
{
	char **av = *args, *home;
	int ret;
	char *error1 = "Error: Unable to change directory\n";
	static char *OLDWD;

	if (OLDWD == NULL) /* if OLDWD is uninitialized */
	{
		OLDWD = malloc(sizeof(char) * 1024);
		if (OLDWD == NULL)
			exit(EXIT_FAILURE);
		_getcwd(&OLDWD);
	}
	if (!av[1]) /* cd $HOME */
	{
		_getcwd(&OLDWD);
		home = malloc(sizeof(char) * BUF_SIZE);
		if (home == NULL)
			exit(EXIT_FAILURE); /* get & change home directory */
		home_dir(&home), ret = chdir(home);
		_setenv("PWD", home, 1);
		if (ret != 0)
			write(2, error1, _strlen(error1));
		free(home);
	} else if (av[1][0] == '-' && av[1][1] == '\0') /* cd - */
	{
		ret = chdir(OLDWD), _setenv("PWD", OLDWD, 1);
		if (ret != 0)
			write(2, error1, _strlen(error1));
	} else
	{
		if (_strcmp(av[1], "exit") == 0)
		{
			free(OLDWD);
			return;
		}
		_getcwd(&OLDWD), ret = chdir(av[1]);
		_setenv("PWD", av[1], 1);
		if (ret != 0)
			write(2, error1, _strlen(error1));
	}
}
