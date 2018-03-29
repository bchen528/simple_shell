#include "shed.h"

/**
 * life - exits main function, produce appropriate error messages,
 * print environment, check if command is executable, fork and execute
 *
 * @array: array of pointers to commandline tokens
 * @argv: current commandline arguments
 * @env: array of environmental variables
 * @p_t: array of pointers to tokenized path
 * @i: number of calls
 * @e_c: exit integer value
 * Return: 1 on fail, 0 on success
 */

int life(char **array, char **argv, char **env, char **p_t, int i, int *e_c)
{
	int error = 0;
	char *ptr = NULL, *a_call_count = NULL;

	if (array != NULL && !(_strcmp(array[0], "exit")))
	{
		if (array[1] == NULL)
			return (1);

		*e_c = custom_atoi(&error, array[1]);
		if (error)
		{
			a_call_count = _itoa(i);
			ERR_EXIT(argv[0], a_call_count, array[1]);
			free(a_call_count);
		}
		else
			return (1);
	}
	else if (array != NULL && !(_strcmp(array[0], "env")))
	{
		print_env(env);
	}
	else if (array != NULL && access(array[0], F_OK) == -1)
	{
		ptr = array[0];
		array[0] = smart_cat(p_t, array[0]);
		if (array[0] == NULL)
		{
			array[0] = _strdup("(nil)");
			a_call_count = _itoa(i);
			ERR_EXE(argv[0], a_call_count, ptr);
			free(a_call_count);
		}
		free(ptr);
	}
	if (array != NULL && _strcmp(array[0], "(nil)"))
		forking_helper(array);

	return (0);
}
