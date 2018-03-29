#include "shed.h"

/**
 * print_env - print the environment list
 *
 * @env: array of pointers to environmental variables
 * Return: 0
 */

int print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
