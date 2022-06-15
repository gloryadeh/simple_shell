#include "shell.h"

/**
 * _setenv - setenv function
 * @envname: environment name
 * @envval: environment value
 * @overwrite: overwrite value
 * Return: 0 on success, else -1
 */
int _setenv(char *envname, char *envval, int overwrite)
{
	int i, j, k = 0, len, ret;
	char *var_name;
	char **new_environ;

	ret = check_name(envname); /* check name for '=' */
	if (ret == -1)
		return (-1);
	var_name = malloc(sizeof(char) * 100);
	if (var_name == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; environ[i]; i++) /* check if variable exists */
	{
		j = 0, k = 0;
		while (environ[i][j] != '=') /* read variable name */
		{
			var_name[k] = environ[i][j];
			k++, j++;
		}
		var_name[k] = '\0';
		if (_strcmp(var_name, envname) == 0) /* if environment var exists */
		{
			if (overwrite != 0) /* overwtrite the variable */
			{
				j++, k = 0; /* go to char after = and reset k */
				while (envval[k] != '\0') /* add new value */
				{
					environ[i][j] = envval[k];
					j++, k++;
				}
				environ[i][j] = '\0';
				return (0);
			}
			else
				return (0);
		}
	}
	/* variable doesn't exist */
	len = len_av(environ); /* get length of environ */
	new_environ = malloc(sizeof(char *) * (len + 2));
	if (new_environ == NULL)
		exit(EXIT_FAILURE);
	i = 0, j = 0, k = 0;
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
	writeenv(&new_environ[i], envname, envval); /* add new variable */
	i++, new_environ[i] = '\0';
	environ = new_environ;
	free(var_name);
	return (0);
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
 * _setenv - setenv function
 * @envname: environment name
 * Return: 0 on success, else -1
 */
int _unsetenv(char *envname)
{
	int i, j, k = 0, ret;
	char *var_name;

	ret = check_name(envname); /* check name for '=' */
	if (ret == -1)
		return (-1);
	var_name = malloc(sizeof(char) * 100);
	if (var_name == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; environ[i]; i++) /* check if variable exists */
	{
		j = 0, k = 0;
		while (environ[i][j] != '=') /* read variable name */
		{
			var_name[k] = environ[i][j];
			k++, j++;
		}
		var_name[k] = '\0';
		if (_strcmp(var_name, envname) == 0) /* if environment var exists */
		{
			while (environ[i])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return (0);
		}
	}
	return (0);
}
