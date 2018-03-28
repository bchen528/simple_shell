#include "shed.h"

void free_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
