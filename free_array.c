#include "shed.h"

void free_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
din();
	while (array[i] != NULL)
	{
win(array[i]);
win(" - FREE\n");
		free(array[i]);
		i++;
	}
/* what if we don't loop through all, huh?
	free(array[i]);
win("free null\n");
*/
	free(array);
win("free array\n");
}
