#ifndef SHEL_L
#define SHEL_L

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);
int print_string(char *string);
int len_av(char **av);
void split_string(char *string, char *delim, char ***array);

#endif /* SHEL_L */
