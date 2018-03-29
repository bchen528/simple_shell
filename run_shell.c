#include "shed.h"

int run_shell(int go)
{
	if (go == -1)
	{
		write(STDIN_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}
