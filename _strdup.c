#include "shed.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: String to be duplicated.
 * Return: pointer to newly allocated space in memory
 * contianing duplicate string.
 */

char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i])
		i++;

	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';

	return (dup);
}
