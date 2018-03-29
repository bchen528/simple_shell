#include "shed.h"

/**
 * free_array - free tokens in array and the array itself
 *
 * @array: array of pointers to tokens
 */

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
