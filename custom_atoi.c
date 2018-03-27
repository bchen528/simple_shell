#include "shed.h"

int custom_atoi(int *status, char *s)
{
	int i, sum, mul, go;

	i = 0;
	sum = 0;
	mul = 1;
	go = 0;

	if (!s)
		return (-1);

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
