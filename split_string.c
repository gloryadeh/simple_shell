#include "shell.h"

/**
 * split_string - splits a string using strtok
 * @string: string
 * @delim: delimeter
 * @array: malloc'ed array of strings
 */
void split_string(char *string, char *delim, char ***array)
{
	/*char *token;*/
	int buffsize = 1024, i = 0;
	char *token;

	/* allocate malloc and get first word */
	*(*array + i) = malloc(sizeof(char *) * buffsize);
	if (!*(*array + i))
	{
		perror("Error: ");
		exit(99);
	}
	printf("About to ...");
	token = strtok(string, delim);
	printf("About to copy string");

	_strcpy(*(*array + i), token);
	/* check if strtok failed */
	if (token == NULL)
	{
		free(*(*array + i));
		return;
	}

	do {
		i++;

		/* allocate malloc and get next word */
		*(*array + i) = malloc(sizeof(char *) * buffsize);
		if (!*(*array + i))
		{
			perror("Error: ");
			exit(99);
		}

		token = strtok(NULL, delim);
		/* check if strtok failed */
		if (token == NULL)
		{
			break;
		}
		_strcpy(*(*array + i), token);
	} while (token != NULL);
	*(*array + i) = '\0';
}
