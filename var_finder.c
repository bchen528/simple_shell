#include "holberton.h"

char *var_finder(char *var, char **env)
{
	int i = 0, ii = 0;

	while (env[ii] != NULL)
	{
		while (var[i] != '\0' && var[i] == env[ii][i])
			i++;
		if (var[i] == '\0')
			return (env[ii]);
		i = 0;
		ii++;
	}
	return (NULL);
}
