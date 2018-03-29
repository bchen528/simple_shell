#include "shed.h"

/**
 * run_shell - check if  getline fails
 *
 * @go: return value of getline function
 * Return: 1 on failure, 0 on success
 */

int run_shell(int go)
{
	if (go == -1)
	{
		write(STDIN_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}
