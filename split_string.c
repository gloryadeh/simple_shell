#include "shell.h"

/**
 * split_string - splits a string using strtok
 * @string: string
 * @delim: delimeter
 * @array: malloc'ed array of strings
 */
void **split_string(char *string, char *delim)
{
	/* declare variables 8*/
	char **args;
	char *token;
	unsigned int length = 0, capacity = 16;

	/* check if string is NULL, print error and exit */
	if (string == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	/* allocate memory for args - where tokens will be stored */
	args = malloc(sizeof(char *) * capacity);
	if (args == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	/* break the string int tokens */
	token = strtok(string, delim);
	while (token != NULL)
	{
		args[length] = token; /* store tokens */
		length++;
		/* reallocate memory if length is greater than capacity */
		/* we'll have to write a function for realloc because we're not allowed to use it*/
		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			args = realloc(args, capacity * sizeof(char*));
		}
		/* continue strtok */
		token = strtok(NULL, delim);
	}
	/* make last char in args NULL */
	args[length] = NULL;
	return (args);
	// /*char *token;*/
	// int buffsize = 1024, i = 0;
	// char *token;
	//
	// /* allocate malloc and get first word */
	// *(*array + i) = malloc(sizeof(char *) * buffsize);
	// if (!*(*array + i))
	// {
	// 	perror("Error: ");
	// 	exit(99);
	// }
	// printf("About to ...");
	// token = strtok(string, delim);
	// printf("About to copy string");
	//
	// _strcpy(*(*array + i), token);
	// /* check if strtok failed */
	// if (token == NULL)
	// {
	// 	free(*(*array + i));
	// 	return;
	// }
	//
	// do {
	// 	i++;
	//
	// 	/* allocate malloc and get next word */
	// 	*(*array + i) = malloc(sizeof(char *) * buffsize);
	// 	if (!*(*array + i))
	// 	{
	// 		perror("Error: ");
	// 		exit(99);
	// 	}
	//
	// 	token = strtok(NULL, delim);
	// 	/* check if strtok failed */
	// 	if (token == NULL)
	// 	{
	// 		break;
	// 	}
	// 	_strcpy(*(*array + i), token);
	// } while (token != NULL);
	// *(*array + i) = '\0';
}
