#include "shed.h"

int main(int argc, char **argv, char **env)
{
/* O make PATH robust and use strcmp to find */
	char **path = (string_token(env[9], ":=") + 1);
/* o FREE path! memory leak! */
	ssize_t run_shell = 0;
	size_t count = 0;
	char *line = NULL, **array = NULL, *ptr = NULL, *free_me_1, *free_me_2;
	int i = 0, exit_code = 0, call_count = 0;

	while (42)
	{
		run_shell = 0;
		count = 0;
		line = NULL;
		array = NULL;
		ptr = NULL;
		i = 0;
		exit_code = 0;
		call_count = 0;

		call_count++;
/* should we write to stdin so it's unpipable */
		write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
		run_shell = getline(&line, &count, stdin);
		if (run_shell == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			return (0);
/*
			perror("Arik, getline failed");
			line = NULL;
*/
		}
		array = string_token(line, "\n ");
		if (array == NULL)
			free(line);
		if (array != NULL && !(strcmp(array[0], "exit")))
		{
/*			write(2, "sh: 1: exit: Illegal number: ", 29);
			write(2, array[0], _strlen(array[0]));
			write(2, "\n", 1);
*/
/* OOO
make custom atoi that returns -1 when being asked to convert something
not number and print out "sh: 1: exit: Illegal number: %s", array[1]
if not number
			exit_code = array[1];
*/
			if (array[1] == NULL)
				break;

			exit_code = custom_atoi(array[1]);
			if (exit_code == -1)
			{
				write(STDIN_FILENO, argv[0], _strlen(argv[0]));
				write(STDIN_FILENO, ": ", 2);
				write(STDIN_FILENO, free_me_1 = _itoa(call_count), _strlen(free_me_2 = _itoa(call_count)));
/*				write(STDIN_FILENO, call_count, _strlen(?:)); */
				write(STDIN_FILENO, ": ", 2);
				write(STDIN_FILENO, "exit", 4);
				write(STDIN_FILENO, ": ", 2);
				write(STDIN_FILENO, "Illegal number", 14);
				write(STDIN_FILENO, ": ", 2);
				free(free_me_1);
				free(free_me_2);
			}
			else
				break;
		}
		if (array != NULL && !(strcmp(array[0], "env")))
		{
			print_env(env);
		}
/*		if (array == NULL)
			array = NULL;
*/
		if (array != NULL && access(array[0], F_OK) == -1)
			array[0] = path_helper(path, array[0]);

		if (forking_helper(array))
		{
/* if fail do thing */
		}
/* OO
create error message that includes 'call_count'
name of program argv[0]
maybe create a pointer 'ptr' for function (i.e. 'ls') and free it later?
*/
/*
		if (execve(array[0], array, NULL) == -1)
			perror("Arik, execve failed");

where should we have errors?
in this main func or in the helper funcs?
*/
		if (array != NULL)
		{
			free(array[0]);
			free(array);
		}
	}
/*	free(ptr);
	free(path); */
	if (array != NULL)
	{
		free(array[0]);
		free(array);
	}
/*
free 'array' if NULL or not?
	if (array != NULL)
		free(array);

	if (line != NULL)
		free(line);
*/

	return (exit_code);
}
