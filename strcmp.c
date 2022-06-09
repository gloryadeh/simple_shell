#include "shell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j, k, l, result;

	/* get length of s1 */
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}

	for (j = 0; j < i; j++)
	{
		result = 0;

		if (s1[j] != s2[j])
		{
			k = s1[j];
			l = s2[j];
			result = k - l;

			break;
		}
	}
	return (result);
}
