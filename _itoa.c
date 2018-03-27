#include "holberton.h"

char *_itoa(int n)
{
	char *s;
	char temp;
	int i = 0, j, count = 0, a;

	while (a > 0)
	{
		a = n / 10;
		count++;
	}
	s = malloc(sizeof(char) * count + 1);
	if (s == NULL)
		return (NULL);

	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	s[i] = '\0';

	i = 0;
	j = _strlen(s) - 1;

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}

	return (s);
}
