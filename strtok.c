#include "shell.h"

/**
 * is_delim - check if character is the delimiter
 * @c: character
 * @delim: delimiter
 * Return: 1 on success
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - breaks a line into tokens
 * @line: line to break up
 * @delim: delimiter
 * Return: pointer to an array of strings (tokens)
 */
char *_strtok(char *line, char *delim)
{
	static char *backup_string; /* start of the next search */
	char *ret;

	if (line == NULL)
	{
		line = backup_string;
		perror("Invalid input\n");
		exit(EXIT_FAILURE);
	}
	/* handling beginning of the string containing delims */
	while (1)
	{
		if (is_delim(*line, delim))
		{
			line++;
			continue;
		}
		if (*line == '\0') /* reach end of string */
			return (NULL);
		break;
	}
	ret = line;
	while (1)
	{
		if (*line == '\0')
		{
			/* end of input string and next exec will return NULL */
			backup_string = line;
			return (ret);
		}
		if (is_delim(*line, delim))
		{
			line = '\0';
			backup_string = line + 1;
			return (ret);
		}
		line++;
	}
}
