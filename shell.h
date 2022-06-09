#ifndef SHEL_L
#define SHEL_L

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int _putchar(char c);
int print_string(char *string);
int len_av(char **av);
char **split_string(char *string, char *delim);
char *_strcpy(char *dest, char *src);
void execute(char **args);
void rem_line(char **buffer);

#endif /* SHEL_L */
