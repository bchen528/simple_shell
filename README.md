# A simple shell

## Description

A recreation of a shell that takes user input (commands with arguments) and outputs accordingly.

Basic loop of a shell:

1. Read command from standard input.
2. Parse commandline string into an executable program and its arguments.
3. Run parsed command.

## Environment
Our custom shell was developed and tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

## Features

- displays a prompt and waits for user to type a command
- can handle commands with options and arguments
- prompt displays again each time command is executed
- uses PATH variable to find executable command
- if executable is not found, prints an error message and displays prompt again
- includes an exit function that exits the shell
- includes an env built-in that prints the current environment

## File Contents
This repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| shell.c | the main function |
| shed.h | header file |
| _itoa.c | custom itoa function |
| _strcmp.c | custom strcmp function |
| _strdup.c | custom strdup function |
| _strlen.c | custom strlen function |
| custom_atoi.c | custom atoi function |
| forking_helper.c | contains function to execute command read from commandline |
| free_array.c | contains function to free array and its tokens |
| life.c | contains a mix of important function calls |
| print_env.c | contains function to print environment |
| run_shell.c | contains function checking if user inputed anything |
| smart_cat.c | contains function concatenating the command to its path directory |
| tokenizer.c | contains function that parses the commandline string |
| var_finder.c | contains function to find PATH variable in environment list |

## Function Descriptions
| **Function** | **Description** |
| -------------- | ----------------- |
| int _strlen(char *s) | find string length |
| int _strcmp(char *s1, char *s2) | compare two strings |
| char **tokenizer(char *str, const char *delim) | tokenizes commandline string |
| int forking_helper(char **av) | executes shell |
| char *stupid_cat(char *path, char *name) | append command name to its directory path to make actual command executable |
| char *_getenv(const char *name) | get value of environment variable |
| char **splitEnv(char *str, const char *delim) | tokenizes environment variable name and its value using |
| char *smart_cat(char **path, char *name) | appends path to command to command |
| int print_env(char **env) | print environment list |
| int custom_atoi(int *status, char *s) | convert character to integer |
| char *_strdup(char *str) | duplicate string |
| char *_itoa(int num) | convert integer to characters |
| char *var_finder(char *var, char **env) | find PATH variable |
| void free_array(char **array) | free tokens in array and array itself |
| int life(char **array, char **argv, char **env, char **p_t, int i, int *e_c) | calling a medley of essential functions |
| int run_shell(int go) | check if command was entered by user |

## Usage

1. Enter custom shell by typing "./hsh". You should be prompted with a ($).
2. Type a command of your liking and press "Enter".
3. Appropriate output will appear.
4. Prompt reappears and awaits your next command.
5. Exit shell by typing "exit"

## Installation
Clone the repository. Compile the ".c" files. Run executable.
```
$ git clone https://github.com/aDENTinTIME/simple_shell.git
```
## Compilation

Enter the following command to compile:
` $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

## Example

Interactive Mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Non-interactive Mode
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Authors

* [**Arik Rosenthal**](https://github.com/aDENTinTIME)
* [**Becky Chen**](https://github.com/bchen528)

## Acknowledgements

We would like to thank the staff and our wonderful peers at Holberton School for providing an effective learning experience throughout this project.

<p align="center">
<a href="https://www.holbertonschool.com"><img width="150" src="https://i.imgur.com/xmkJjII.jpg"></a>
</p>
