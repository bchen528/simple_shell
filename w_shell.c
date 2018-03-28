#include "shed.h"

/**
 * main - A simple shell that will execute programs in the system.
 *
 * @argc: Number of arguments from command line, passed to shell at launch.
 * @argv: Array of arguments passed to shell at launch.
 * @env: Array of enviromental variables.
 * Return: Exit code of 0 upon success, or number given to "exit"
 */

int main(int argc, char **argv, char **env)
{
	char **free_path_token = tokenizer(var_finder("PATH", env), ":=");
	char **path_token = free_path_token + 1;
	ssize_t run_shell = 0;
	size_t count = 0;
	char *line = NULL, **array = NULL, *a_call_count = NULL;
	int exit_code = 0, call_count = 0, error = 0;
	(void)argc;

	while (42)
	{
		run_shell = 0;
		count = 0;
		line = NULL;
		array = NULL;
		a_call_count = NULL;
		exit_code = 0;
		error = 0;
		call_count++;

		write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
		run_shell = getline(&line, &count, stdin);
		if (run_shell == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		array = tokenizer(line, "\n ");
		if (line != NULL)
			free(line);

		if (array != NULL && !(_strcmp(array[0], "exit")))
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
		else if (array != NULL && !(_strcmp(array[0], "env")))
		{
			print_env(env);
		}
		else if (array != NULL && access(array[0], F_OK) == -1)
		{
			array[0] = smart_cat(path_token, array[0]);
			if (array[0] == NULL)
				array[0] = _strdup("(nil)");
		}
		if (array != NULL && _strcmp(array[0], "(nil)"))
			forking_helper(array);
/* OO
create error message that includes 'call_count'
name of program argv[0]
maybe create a pointer 'ptr' for function (i.e. 'ls') and free it later?
*/
		free_array(array);
	}
	free_array(free_path_token);
	free_array(array);
	return (exit_code);
}
