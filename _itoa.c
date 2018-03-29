#include "shed.h"

/**
 * _itoa - convert integer to char
 *
 * @num: integer to be converted
 * Return: character string of number
 */

char *_itoa(int num)
{
	char *s;
	int i = 0, num_cpy = num;

	while (num_cpy > 0)
	{
		num_cpy /= 10;
		i++;
	}

	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);

	s[i] = '\0';

	while (i--)
	{
		s[i] = (num % 10) + '0';
		num /= 10;
	}

	return (s);
}
