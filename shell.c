#include "shed.h"

/**
 *
 *
 *
 *
 *
 *
 */

int main(int argc, char **argv, char **env)
{
	char **free_path_token = tokenizer(var_finder("PATH", env), ":=");
	char **path_token = free_path_token + 1;
	ssize_t run_shell = 0;
	size_t count = 0;
	char *line = NULL, **array = NULL, *ptr = NULL, *a_call_count;
	int i = 0, exit_code = 0, call_count = 0, error = 0;

	while (42)
	{
		run_shell = 0;
		count = 0;
		line = NULL;
		array = NULL;
		ptr = NULL;
		a_call_count = NULL;
		i = 0;
		exit_code = 0;
		error = 0;
		call_count++;

		write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
		run_shell = getline(&line, &count, stdin);
		if (run_shell == -1)
		{
/* remove perror */
			perror("run_shell -1");
			write(STDIN_FILENO, "\n", 1);
			return (0);
/*
			perror("Arik, getline failed");
			line = NULL;
*/
		}
		array = tokenizer(line, "\n ");
		if (array == NULL)

			free(line);
/*		win("tokenizer failed y'all\n"); */
/* use OUR _strcmp */
		if (array != NULL && !(strcmp(array[0], "exit")))
		{
			if (array[1] == NULL)
				break;

			exit_code = custom_atoi(&error, array[1]);
			if (error)
			{
				a_call_count = _itoa(call_count);
/* do NOT use perror here */
				WERR(argv[0], a_call_count, array[0], "Illegal number", array[1]);
				free(a_call_count);
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
		{
/*
			ptr = array[0];
win(ptr);
win(array[0]);
			array[0] = exe_cat(path_token, array[0]);
			free(ptr);
*/

			array[0] = exe_cat(path_token, array[0]);

/*			ptr = exe_cat(path_token, array[0]);
			free(array[0]);
			array[0] = ptr;
*/
		}
		if (forking_helper(array))
		{
			perror("forking failed y'all");
/* if fail print error */
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
/*	if (line != NULL)
		free(line);
*/
/*	free_array(array); */
	}
/*	free(ptr); */

	free(free_path_token);
	free_array(array);
/*
	if (line != NULL)
		free(line);

	if (array != NULL)
	{
		free(array[0]);
		free(array);
	}
*/
/*
free 'array' if NULL or not?
	if (array != NULL)
		free(array);

	if (line != NULL)
		free(line);
*/

	return (exit_code);
}
