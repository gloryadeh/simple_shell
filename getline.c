#include "shell.h"

/**
 * _getchar - reads an input of a character
 *
 * Return: contents of the buffer one character at a time
 */
int _getchar(void)
{
	/* declare static variables and c */
	static char buffer[MAX];
	static int start;
	static int end;
	int c = 0;

	if (start == end)
	{
		c = read(0, buffer, MAX); /* read character */
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
 * @buffer: pointer to malloc'ed string
 */
void _getline(char **buffer)
{
	/* declare variables */
	char *line = *buffer;
	int c, i, bufsize;

	bufsize = BUF_SIZE; /* BUF_SIZE declared in shell.h */
	i = 0;
	while (1) /* loop continues till EOF */
	{
		c = _getchar(); /* getchar and store in c */
		if (c == EOF)
		{
			line[i] = EOF;
			return;
		}
		else if (c == '\n')
		{
			line[i] = '\0';
			return;
		}
		else /* c is not EOF or newline, line[i] = c */
			line[i] = c;
		i++;
		/* reallocation process */
		if (i >= BUF_SIZE)
		{
			bufsize += BUF_SIZE; /* increase bufsize by adding BUF_SIZE */
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
