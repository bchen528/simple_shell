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
	char **path_token = free_path_token + 1, *line = NULL, **array = NULL;
	ssize_t go = 0;
	size_t count = 0;
	int exit_code = 0, i = 0;
	(void)argc;

	while (42)
	{
		count = 0;
		line = NULL;
		array = NULL;
		i++;
		write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
		go = getline(&line, &count, stdin);
		if (run_shell(go))
		{
			free(line);
			break;
		}
		if (line != NULL)
		{
			if (line[0] == '\n')
			{
				free(line);
				line = NULL;
			}
		}
		if (line != NULL)
		{
			array = tokenizer(line, "\n ");
			free(line);
		}
		if (life(array, argv, env, path_token, i, &exit_code))
			break;
		free_array(array);
	}
	free_array(free_path_token);
	free_array(array);
	return (exit_code);
}
