#include "shell.h"

/**
 * gtline - assigns the line var for _getline
 * @lineptr: buffer that stores input string
 * @buffer: string being called to line
 * @n: size of line
 * @j: size of buffer
 */
void gtline(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if ((lineptr == NULL) || (*n < j))
	{
		if (j > BUF_SIZE)
			*n = j;
		else
			*n = BUF_SIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * _getline - reads input from stream
 * @lineptr: buffer that stores input string
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	/* flush or clear output buffer of stream */
	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUF_SIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[i] = t;
		input++;
	}
	buffer[input] = '\0';
	gtline(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
