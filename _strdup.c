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
	int i;
	char *dup;
	int size;

	if (str == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	size = size + 1;
	dup = (char *)malloc(sizeof(char) * size);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
