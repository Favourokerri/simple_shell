#include "shell.h"

/**
 * create_error - Writes a custom error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */
int create_error(char **args, int err)
{
	char *error;

	if (err == -1)
	{
		error = error_env(args);
	}
	else if (err == 1)
	{
		error = error_1(args);
	}
	else if (err == 2)
	{
		if (*(args[0]) == 'e')
		{
			error = error_2_exit(++args);
		}
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
		{
			error = error_2_syntax(args);
		}
		else
		{
			error = error_2_cd(args);
		}
	}

	return (err);
}
