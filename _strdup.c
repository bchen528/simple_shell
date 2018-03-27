#include "shed.h"

/**
 * *_strdup - return pointer to newly allocated space
 * in memory containing a copy of a string
 * @str: string to be copied
 * Return: pointer to newly allocated space in memory
 * contianing duplicate string
 */

char *_strdup(char *str)
{
	int i = 0;
	char *dup;
	int size = 0;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;

	dup = malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (NULL);

	while (i < (size + 1))
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
