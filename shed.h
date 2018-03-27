#ifndef SHED_H
#define SHED_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define win(x) write(STDOUT_FILENO, x, _strlen(x))
#define din() write(STDOUT_FILENO, "###\n", 4)

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **string_token(char *in, char *delim);
char **tokenizer(char *str, const char *delim);
char *path_helper(char **path, char *name);
char *stupid_cat(char *path, char *name);
int forking_helper(char **av);
int print_env(char **env);
char *_itoa(int n);
#endif /* SHED_H */
