#ifndef SHEL_L
#define SHEL_L
#define MAX 1024
#define BUF_SIZE 200
#define ARG_SIZE 10

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
	void (*function)(char ***);
} built_in;

/* builtin functons */
void print_env(char ***args);
void exit_prog(char ***args);
void _setenv(char ***args);
void _unsetenv(char ***args);

/* utility functions */
int _putchar(char c);
int print_string(char *string);
int len_av(char **av);
char **split_string(char *string, char *delim);
char *_strcpy(char *dest, char *src);
void execute(char **args, char **argv);
void rem_line(char **buffer);
int _strcmp(char *s1, char *s2);
int run_builtin(built_in builtin[], char ***args);
void rename_ls(char ***args);
int _strlen(char *s);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _getline(char **buffer);
int _getchar(void);
char *_strtok(char *line, char *delim);
unsigned int is_delim(char c, char *delim);

#endif /* SHEL_L */
