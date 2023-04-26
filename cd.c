#include "shell.h"

/**
 * cd_handler - change current working directory
 * @array: array of arguments
 * @env: array of environment variables
 *
 * Return: always 0
 */
int cd_handler(char **array, char **env)
{
	int cwd_len = 0;
	char cwd[1024];
	char *new_cwd_path;

	if (array[1] == NULL)
	{
		if (chdir(_getenv("HOME", env)) == -1)
		{
			perror(array[0]);
			write(STDERR_FILENO, "cd: can't cd to home\n", 21);
		}
	}
	else
	{
		getcwd(cwd, 1024);
		while (cwd[cwd_len] != '\0')
			cwd_len++;
		cwd[cwd_len++] = '/';
		cwd[cwd_len] = '\0';
		new_cwd_path = _strconcat(cwd, array[1]);
		if (new_cwd_path == NULL)
			return (0);
		if (chdir(new_cwd_path) == -1)
		{
			perror(array[0]);
			write(STDERR_FILENO, "can't cd into directory\n", 24);
		}
		free(new_cwd_path);
	}
	return (0);
}
