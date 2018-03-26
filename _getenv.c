#include "shed.h"

extern char **environ;

/**
 * splitEnv - tokenizes a given string
 * @str: string to be parsed
 * @delim: the delimiter
 * Return: array of pointers to tokens
 */

char **splitEnv(char *str, const char *delim)
{
        char *token;
        char **buf;
        int i = 0, j = 0, count = 2;

/*allocate space for array of pointers to tokens*/

        buf = malloc(sizeof(char *) * count + 1);
        if (buf == NULL)
                return (NULL);

/*first word is command*/
        token = strtok(str, delim);

/*assign other parameters to buffer*/

        while (token != NULL)
        {
                buf[j] = strdup(token);
                token = strtok(NULL, delim);
                j++;
        }
        buf[j] = NULL;

        return (buf);
}

/**
 * _getenv - get an environment variable
 * @name: string containing name of the requested variable
 * Return: null-terminated string with value of 
 * requested environment variable, or
 * NULL if environment variable DNE
 */

char *_getenv(const char *name)
{
	char **buf;
	char *value;
	int i = 0;

	while (environ[i] != NULL)
	{
		buf = splitEnv(environ[i], "=");

		if (strcmp(buf[0], name) == 0)
		{
			value = buf[1];
			break;
		}
		else if (environ[i] == NULL)
			return (NULL);
		i++;
	}
	return (value);

}
int main(void)
{
	printf("PATH: %s\n", _getenv("PATH"));
	return (0);
}
