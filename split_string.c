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
	token = strtok(string, delim);
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
		token = strtok(NULL, delim);
		length++;
		/* continue strtok */
	}
	/* make last char in args NULL */
	args[length] = NULL;
	return (args);
}
