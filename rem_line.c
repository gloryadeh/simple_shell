#include "shell.h"

/**
 * rem_line - removes trailing new line
 * @buffer: string
 */
void rem_line(char **buffer)
{
	unsigned int i, j;

	/* iterate through the string */
	for (i = 0; buffer[0][i]; i++)
	{
		/* check for new line */
		if (buffer[0][i] == '\n')
		{
			/* replace new line with null byte */
			for (j = i; buffer[0][j]; j++)
				buffer[0][j] = buffer[0][j + 1];
		}
	}
}
