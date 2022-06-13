#include "shell.h"

/**
 * _getchar - reads an input of a character
 *
 * Return: contents of the buffer one character at a time
 */
int _getchar(void)
{
	static char buffer[MAX];
	static int start;
	static int end;
	int c = 0;

	if (start == end)
	{
		c = read(0, buffer, MAX);
		if (c == 0)
			return (EOF);
		start = 0;
		end = c;
	}
	if (c >= 0)
		return (buffer[start++]);
	return (EOF);
}

/**
 * _getline - reads a line from stdin
 *
 * Return: pointer to the line
 */
char *_getline(void)
{
	char *line;
	int c, index, bufsize;

	bufsize = BUF_SIZE;
	line = malloc(sizeof(char) * BUF_SIZE);
	if (line == NULL)
	{
		perror("Failed to allocate memory\n");
		return (NULL);
	}
	index = 0;
	while (1)
	{
		c = _getchar();
		if (c == EOF)
		{
			line[index] = EOF;
			return (line);
		}
		else if (c == '\n')
		{
			line[index] = '\0';
			return (line);
		}
		else
			line[index] = c;
		index++;
		if (index >= BUF_SIZE)
		{
			bufsize += BUF_SIZE;
			line = _realloc(line, bufsize - BUF_SIZE, bufsize);
			if (line == NULL)
			{
				perror("Failed to allocate memory\n");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
}
