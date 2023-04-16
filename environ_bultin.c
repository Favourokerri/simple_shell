#include "shell.h"
/**
 * _env - prints the current environment
 * @arguments: command line arguements
 * @unused_para: pointer
 * Return: 1 if environ in empty
 */

int _env(char **arguments, char __attribute__((__unused__)) **unused_para)
{
	int index;
	char tab = '\t';

	if (!environ)
		return (1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &tab, 1);
		write(STDOUT_FILENO, arguments[0], _strlen(arguments[0]));
		write(STDOUT_FILENO, &tab, 1);
	}

	return (0);
}
