#include "shed.h"

extern char **environ;

/**
 * main - prints the environment using environ
 *
 * Return: 0
 */

int main(void)
{
	int i = 0;
	
	while (environ[i] != '\0')
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
