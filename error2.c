#include "shell.h"

/**
 * create_error2 - Writes a custom error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */
int create_error2(char **args, int err)
{
	char *error;

	else if (err == 126)
	{
		error = error_126(args);
	}
	else if (err == 127)
	{
		error = error_127(args);
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		ree(error);
	}

	return (err);
}
