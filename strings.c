#include "shell.h"

/**
 * split_string - splits a string using strtok
 * @string: string
 * @delim: delimiter
 * Return: malloc'ed array of strings
 */
char **split_string(char *string, char *delim)
{
	/* declare variables 8*/
	char **args;
	char *token;
	unsigned int length = 0, capacity = 50;

	/* check if string is NULL, print error and exit */
	if (string == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	/* allocate memory for args - where tokens will be stored */
	args = malloc(sizeof(char *) * capacity);
	if (args == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	/* break the string into tokens */
	token = _strtok(string, delim);
	while (token != NULL)
	{
		/* allocate spcae for each string */
		args[length] = malloc(sizeof(char) * 1024);
		if (args[length] == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		_strcpy(args[length], token); /* store tokens */
		token = _strtok(NULL, delim);
		length++;
		/* continue strtok */
	}
	/* make last char in args NULL */
	args[length] = NULL;
	return (args);
}

/**
 * _strcmp - compares 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j, k, l, result;

	/* get length of s1 */
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}

	for (j = 0; j < i; j++)
	{
		result = 0;

		if (s1[j] != s2[j])
		{
			k = s1[j];
			l = s2[j];
			result = k - l;

			break;
		}
	}
	return (result);
}

/**
* *_strcpy - copies the string pointed
*@dest: copie of the string
*@src: origin of the string
*Return: dest destine copie
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
