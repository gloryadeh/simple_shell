#include "shell.h"

/**
 * _strlen - computes length of a string
 * @s: string
 * Return: length of string, -1 if error
 */
int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
