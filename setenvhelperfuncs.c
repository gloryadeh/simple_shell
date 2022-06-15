#include "shell.h"

/**
 * read_var_name - read variable name
 * @i: index of string
 * @var_name: pointer to string to store variable name
 * Return: j
 */
int read_var_name(int i, char **var_name)
{
	int j = 0, k = 0;
	char *var = *var_name;

	while (environ[i][j] != '=') /* read variable name */
	{
		var[k] = environ[i][j];
		k++, j++;
	}
	var[k] = '\0';
	return (j);
}

/**
 * writeenv - writes a new environment variable
 * @new_environ: pointer to new array
 * @envname: environment name
 * @envval: environment value
 */
void writeenv(char **new_environ, char *envname, char *envval)
{
	int i = 0, j = 0;
	char *env = *new_environ;

	while (envname[i])
	{
		env[i] = envname[i];
		i++;
	}
	env[i] = '=';
	i++;
	while (envval[j])
	{
		env[i] = envval[j];
		i++, j++;
	}
	env[i] = '\0';
}

/**
 * check_name - check env name for =
 * @envname: env name
 * Return: 0 if it doesn't have, else -1
 */
int check_name(char *envname)
{
	int i = 0;

	while (envname[i])
	{
		if (envname[i] == '=')
			return (-1);
		i++;
	}
	return (0);
}

/**
 * copyenv - copies environ into new array
 * @environm: pointer to new array
 * Return: i
 */
int copyenv(char ***environm)
{
	int i = 0;
	char **new_environ = *environm;

	while (environ[i]) /* copy environ into new array */
	{
		new_environ[i] = malloc(sizeof(char) * 4096);
		if (new_environ[i] == NULL)
			exit(EXIT_FAILURE);
		_strcpy(new_environ[i], environ[i]); /* copy variable */
		i++;
	}
	new_environ[i] = malloc(sizeof(char) * 1024);
	if (new_environ[i] == NULL)
		exit(EXIT_FAILURE);

	return (i);
}
