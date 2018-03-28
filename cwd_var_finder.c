#include "shed.h"

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
			return (env[ii] + i + 1);
		ii++;
	}
	return (NULL);
}
