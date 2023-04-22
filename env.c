#include "shell.h"

/**
 * env_handler - handles the env builtin
 * @env: environment variable
 * Return: 0 on success
 */

int env_handler(char **env)
{
	int i = 0, length = 0;

	while (env[i] != NULL)
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * _getenv - find the value of an environment variable
 * @name: the name of the environment variable to find
 * @env: the environment variables array
 *
 * Return: a pointer to the emvironment
 */

char *_getenv(const char *name, char **env)
{
	int env_index = 0;
	int name_index = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);

	while (env[env_index] != NULL)
	{
		while (env[env_index][name_index] == name[name_index])
			name_index++;

		if (env[env_index][name_index] == '=')
		{
			name_index++;
			return (&(env[env_index][name_index]));
		}

		env_index++;
		name_index = 0;
	}

	write(STDOUT_FILENO, "Not found in environment", 24);
	return (NULL);
}

/**
 * path_handler - iterates through PATH variable and
 * concatenates command
 * @command: command to concatenate with the directories in PATH
 * @env: the environment variables array
 *
 * Return: a pointer to the concatenated string
 */

char *path_handler(char *command, char **env)
{
	char *path,  *directory;
	linked_t *list, *tmp;
	struct stat st;

	if (command == NULL || env == NULL || *env == NULL)
		return (NULL);
	path = _getenv("PATH", env);
	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH not found", 14);
		_exit(0);
	}
	list = create_linkedt(path);
	if (list == NULL)
	{
		write(STDERR_FILENO, "Issues with PATH", 16);
		_exit(0);
	}
	list = addnodes_list(path, list);
	tmp = list;
	while (tmp != NULL)
	{
		if (path[0] == ':')
			directory = _strconcat("./", command);
		else
			directory = _strconcat(tmp->directory, command);

		if (directory == NULL)
			return (NULL);
		if (stat(directory, &st) == 0 && access(directory, X_OK) == 0)
		{
			free_list(list);
			return (directory);
		}

		tmp = tmp->next;
		free(directory);
	}
	free_list(list);
	return (NULL);
}
