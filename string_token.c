#include "shed.h"

char **string_token(char *in, char *delim)
{
	int i;
	char *in_1, *in_2, *ptr, **ar;

	if (!(in) || !(delim))
		return (NULL);
/* ^ do we need? ^ */
	in_1 = NULL;
	in_2 = NULL;
	ptr = NULL;
	ar = NULL;
/*duplicate string*/
	in_1 = _strdup(in);
	in_2 = _strdup(in);
	if (in_1 == NULL)
		return (NULL);
/*find number of tokens*/
	ptr = strtok(in_1, delim);
/*check if strtok failed*/
	if (ptr == NULL)
		return (NULL);
/*loop, count tokens*/
	for (i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, delim);
	}
	ar = malloc(sizeof(char *) * (i + 1));
	if (ar == NULL)
		return (NULL);

	ptr = strtok(in_2, delim);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr != NULL; i++)
	{
		ar[i] = ptr;
		ptr = strtok(NULL, delim);
	}

	ar[i] = NULL;

/*
free 'ptr'? free 'ar' back in main??
changed to '\0'
ar[i] = NULL; //what i had before
I put it back to NULL
*/

	free(in_1);

	return (ar);
}
