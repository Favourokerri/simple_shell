#include "shell.h"

/**
 * read_command - reads users input
 * Return: input of the user
 */

char *read_command(void)
{
	char *command;

	size_t n = 0;

	ssize_t char_read = 0;

	command = (char *)malloc(sizeof(char) * n);
	char_read = getline(&command, &n, stdin);
	
	if (char_read == EOF)
	{
		free(command);
		return NULL;
	}
	return (command);
}
