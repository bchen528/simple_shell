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

#endif /* SHED_H */
