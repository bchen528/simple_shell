#include "shed.h"

/**
 * tokenizer -
 *
 * @str -
 * @delim -
 * Return:
 */


char **tokenizer(char *str, const char *delim)
{
	int i = 0;
	char *str_1 = NULL, *str_2 = NULL, *ptr = NULL, **ar = NULL;

	if (!(str) || !(delim))
		return (NULL);

	str_1 = _strdup(str);
	str_2 = _strdup(str);
	if (!(str_1) || !(str_2))
		return (NULL);

	ptr = strtok(str_1, delim);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, delim);
	}

	ar = malloc(sizeof(char *) * (i + 1));
	if (ar == NULL)
		return (NULL);

	ptr = strtok(str_2, delim);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ar[i] = _strdup(ptr);
		ptr = strtok(NULL, delim);
	}

	ar[i] = NULL;
	free(str_1);
	return (ar);
}
