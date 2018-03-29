#include "shed.h"

/**
 * var_finder - find the PATH variable in environment list
 *
 * @var: string literal of desired environmental variable
 * @env: environment list
 * Return: string of desired environment variable and its value
 */

char *var_finder(char *var, char **env)
{
	int i = 0, ii = 0;

	if (!(var) || !(env))
		return (NULL);

	while (env[ii] != NULL)
	{
		i = 0;
		while (var[i] != '\0' && var[i] == env[ii][i])
			i++;
		if (var[i] == '\0')
			return (env[ii]);
		ii++;
	}
	return (NULL);
}
