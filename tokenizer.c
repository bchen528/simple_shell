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
	int i = 0, k = 0, count = 0;
	char *ptr = NULL, **ar = NULL;

	if (!(str) || !(delim))
		return (NULL);

    while (delim[k] != '\0')
    {
        while (str[i] != '\0')
        {
            if (str[i] == delim[k])
                count++;
            i++;
        }
        i = 0;
        k++;
    }

	ar = malloc(sizeof(char *) * (count + 1));
	if (ar == NULL)
		return (NULL);

	ptr = strtok(str, delim);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ar[i] = _strdup(ptr);
		ptr = strtok(NULL, delim);
	}

	ar[i] = NULL;
	return (ar);
}