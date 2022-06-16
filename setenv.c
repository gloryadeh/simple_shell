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
	int i, j, k, len, ret;
	char *var_name, **new_environ;

	ret = check_name(envname); /* check name for '=' */
	if (ret == -1)
		return (-1);
	var_name = malloc(sizeof(char) * 100); /* allocate memory for var_name */
	if (var_name == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; environ[i]; i++) /* check if variable exists */
	{
		j = read_var_name(i, &var_name); /* read var name and get j */
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
				environ[i][j] = '\0', free(var_name);
				return (0);
			}
		}
	} /* variable doesn't exist */
	len = len_av(environ); /* get length of environ */
	new_environ = malloc(sizeof(char *) * (len + 2));
	if (new_environ == NULL)
		exit(EXIT_FAILURE);
	i = copyenv(&new_environ); /* copy environ to new_environ */
	writeenv(&new_environ[i], envname, envval); /* add new variable */
	i++, new_environ[i] = '\0';
	environ = new_environ;
	free(var_name);
	for (i = 0; new_environ[i]; i++)
		free(new_environ[i]);
	free(new_environ);
	return (0);
}

/**
 * _unsetenv - unsetenv function
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
	free(var_name);
	return (0);
}
