#include "shed.h"

char *path_helper(char **path, char *name)
{
	int i = 0;
	DIR *dir;
	struct dirent *dd;

	if (!(path) || !(name))
		return (NULL);

	while (path[i])
	{
		if (!(dir = opendir(path[i])))
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
