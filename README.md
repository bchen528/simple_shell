# A simple shell

## Description

A recreation of a shell that takes user input (commands with arguments) and outputs accordingly.

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
| string\_helpers.c | contains functions that manipulate and tokenize a string |
| exe\_helpers.c | contains functions that assist in executing a command read from the commandline |
| env\_helpers.c | contains functions that utilize the PATH variable to access executable file of command |

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

```


```

## Authors

* [**Arik Rosenthal**](https://github.com/aDENTinTIME)
* [**Becky Chen**](https://github.com/bchen528)

## Acknowledgements

We would like to thank the staff and our wonderful peers at Holberton School for providing an effective learning experience throughout this project.

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>