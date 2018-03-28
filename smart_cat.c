#include "shed.h"

char *smart_cat(char **path, char *name)
{
	char *buff = NULL;
	int i = 0, ii = 0, v = 0;

	if (!(path) || !(name))
		return (NULL);

	while (path[v] != NULL)
	{
		buff = malloc(sizeof(char) * (_strlen(path[v]) + _strlen(name) + 2));
		if (!(buff))
			return (NULL);

		i = 0;
		ii = 0;
		while (path[v][ii])
		{
			buff[i] = path[v][ii];
			i++;
			ii++;
		}
		buff[i] = '/';
		i++;
		ii = 0;
		while (name[ii])
		{
			buff[i] = name[ii];
			i++;
			ii++;
		}
		buff[i] = '\0';

		if (access(buff, F_OK) == 0)
		{
			return (buff);
		}
		else
			free(buff);
		v++;
	}
	return (NULL);
}
