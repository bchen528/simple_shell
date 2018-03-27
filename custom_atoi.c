#include "shed.h"

int custom_atoi(char *s)
{
	int i, sum, mul;

	i = 0;
	sum = 0;
	mul = 1;

	if (!s)
		return (-1);

	while (s[i])
	{
		i++;
	}

	while (i--)
	{
		if (s[i] > 57 || s[i] < 48)
			return (-1);
		sum += (s[i] - 48) * mul;
		mul *= 10;
	}

	if (s[0] == '-')
		sum *= -1;

	return (sum);
}
