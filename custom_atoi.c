#include "shed.h"

/**
 * custom_atoi - convert a character-represented number into an integer
 *
 * @status: flag representing whether character is a number or not
 * @s: character string
 * Return: converted integer
 */

int custom_atoi(int *status, char *s)
{
	int i, sum, mul;

	i = 0;
	sum = 0;
	mul = 1;

	while (s[i])
	{
		i++;
	}

	while (i--)
	{
		if (s[i] > 57 || s[i] < 48)
			*status = 1;
		sum += (s[i] - 48) * mul;
		mul *= 10;
	}

	return (sum);
}
