#include "shell.h"

/**
 * env_error_message - generates an error message
 * @args: a pointer to an array of strings
 *
 * Return: a pointer to a string containing the error message
 */
char *env_error_message(char **args)
{
	char *err_msg;

	char *hist_count_str;

	int total_len;

	hist_count_str = _itoa(history_count); /* convert to string */
	if (hist_count_str == NULL)
	{
		return (NULL);
	}

	args--;
	total_len = _strlen(name) + _strlen(hist_count_str) + _strlen(args[0]) + 45;
	err_msg = malloc(sizeof(char) * (total_len + 1));

	if (err_msg == NULL)
	{
		free(hist_count_str);
		return (NULL);
	}

	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, hist_count_str);
	_strcat(err_msg, ": ");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, ": cannot add this environment\n");

	free(hist_count_str);
	return (err_msg);
}
