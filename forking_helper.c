#include "shed.h"

int forking_helper(char **av)
{
	pid_t forking_val;

	if (!(av))
		return (1);

	forking_val = fork();
	if (forking_val == -1)
	{
/*		perror("Forking failed"); */
		return (1);
	}

	if (forking_val == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			exit(1);
		}
	}
	else
	{
		wait(NULL);
		return (0);
	}

	return (0);
}
