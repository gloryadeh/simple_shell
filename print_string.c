#include "shell.h"

/**
 * print_string - print string
 * @string: string
 * Return: number of characters
 */
int print_string(char *string)
{
	int len = 0;

	if (string == NULL)
		return (-1);

	while (string[len] != '\0')
	{
		_putchar(string[len]);
		len++;
	}
	_putchar(':');
	return (len);
}
