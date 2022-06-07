#ifndef SHEL_L
#define SHEL_L

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);
int print_string(char *string);
int len_av(char **av);
char **split_string(char *string, char *delim);
char *_strcpy(char *dest, char *src);

#endif /* SHEL_L */
