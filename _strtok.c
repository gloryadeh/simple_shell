#include "shell.h"

/**
 * split_string - splits a string
 * @string: string
 * @delim: delimeter
 * Return: array of string
 */
char **split_string(char * string, char * delim)
{
	char **array;
	char *token;
	int buffsize = 1024, i = 0, j;

	array = malloc(sizeof(char) * buffsize);
	if (!array)
	{
		perror("Error: ");
		exit(99);
	}
	token = malloc(sizeof(char) * buffsize);
	if (!token)
	{
		perror("Error: ");
		exit(99);
	}
	token = strtok(string, delim);
	while(token != NULL)
	{
		array[i] = malloc(sizeof(char) * buffsize);
		if (!array[i])
		{
			j = i - 1;
			while(j >= 0)
			{
				free(array[j]);
				j--;
			}
			free(array);
			perror("Error: ");
			exit(99);
		}
		array[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	array[i] = '\0';

	return (array);
}
