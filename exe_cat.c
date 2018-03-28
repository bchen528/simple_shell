#include "shed.h"

char *exe_cat(char **path, char *name)
{
	int i = 0;
	DIR *dir;
	struct dirent *dd;

	if (!(path) || !(name))
		return (NULL);

	while (path[i])
	{
		dir = opendir(path[i]);
		if (!(dir))
			return (NULL);
		while (dd = readdir(dir))
		{
			if (!(strcmp(dd->d_name, name)))
			{
				closedir(dir);
				return (stupid_cat(path[i], name));
			}
		}
		i++;
	}

	closedir(dir);

	return (NULL);
}
