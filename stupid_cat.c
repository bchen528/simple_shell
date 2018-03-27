#include "shed.h"

char *stupid_cat(char *path, char *name)
{
	char *buff;
	int i, ii;

	if (!(path) || !(name))
		return (NULL);

	buff = malloc(sizeof(char) * (_strlen(path) + _strlen(name) + 2));
	if (!(buff))
		return (NULL);

	i = 0;
	ii = 0;
	while (path[ii])
	{
		buff[i] = path[ii];
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

	return (buff);
}
