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

	/* allocate malloc and get first word */
	*(*array + i) = malloc(sizeof(char *) * buffsize);
	if (!*(*array + i))
	{
		perror("Error: ");
		exit(99);
	}
	*(*array + i) = strtok(string, delim);
	/* check if strtok failed */
	if (*(*array + i) == NULL)
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

		*(*array + i) = strtok(NULL, delim);
		/* check if strtok failed */
		if (*(*array + i) == NULL)
		{
			free(*(*array + i));
			return;
		}
	} while (*(*array + i) != NULL);
	*(*array + i) = '\0';
}
