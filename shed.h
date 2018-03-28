#ifndef SHED_H
#define SHED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define win(x) write(STDOUT_FILENO, x, _strlen(x))
#define din() write(STDOUT_FILENO, "###\n", 4)

#define WERR(a, b, c, d, e)\
do {\
	write(STDIN_FILENO, a, _strlen(a));\
	write(STDIN_FILENO, ": ", 2);\
	write(STDIN_FILENO, b, _strlen(b));\
	write(STDIN_FILENO, ": ", 2);\
	write(STDIN_FILENO, c, _strlen(c));\
	write(STDIN_FILENO, ": ", 2);\
	write(STDIN_FILENO, d, _strlen(d));\
	write(STDIN_FILENO, ": ", 2);\
	write(STDIN_FILENO, e, _strlen(e));\
	write(STDIN_FILENO, "\n", 1);\
} while (0)

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **tokenizer(char *str, const char *delim);
char *exe_cat(char **path, char *name);
char *stupid_cat(char *path, char *name);
int forking_helper(char **av);
int print_env(char **env);
int custom_atoi(int *status, char *s);
char *_strdup(char *str);
char *_itoa(int num);
char **splitEnv(char *str, const char *delim);
char *_getenv(const char *name, char **env);
char *var_finder(char *var, char **env);
#endif /* SHED_H */
