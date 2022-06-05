#include "shell.h"

/**
 * len_av - get length of an array of strings
 * @av: av
 * Return: length of string
 */
int len_av(char **av)
{
	int len = 0;

	while (av[len])
		len++;

	return (len);
}
