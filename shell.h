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

extern char **environ;
/**
 * struct builtin - struct of av[0] keywords and related functions
 * @argument: av[0]
 * @function: functon to call
 */
typedef struct builtin
{
	char *argument;
	void (*function)(void);
} built_in;

int _putchar(char c);
int print_string(char *string);
int len_av(char **av);
char **split_string(char *string, char *delim);
char *_strcpy(char *dest, char *src);
void execute(char **args);
void rem_line(char **buffer);
void exit_prog(void);
int _strcmp(char *s1, char *s2);
int run_builtin(built_in builtin[], char *argument);
void print_env(void);

#endif /* SHEL_L */
