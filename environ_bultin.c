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

	if (environ != NULL)
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

/**
 * _getenv - Gets the value of an environment variable.
 * @s: The name of the variable to get.
 *
 * Return: A pointer to the value of the environment variable, or NULL if it
 *         does not exist.
 */

char **_getenv(const char *s)
{
	int current_index, name_length;

	name_length = _strlen(s);
	for (current_index = 0; environ[current_index]; current_index++)
	{
		if (_strncmp(s, environ[current_index], name_length) == 0)
			return (&environ[current_index]);
	}

	return (NULL);
}

/**
 * _setenv - to set the value of an environment variable
 * @arguments: arguements
 * @unused_para: unused parameter
 * Return: 0 on success else -1
 */

int _setenv(char **arguments, char __attribute__((__unused__)) **unused_para)
{
	char **env_var_ptr = NULL, **new_environ_ptr, *new_value_ptr;
	size_t environ_size;
	int index;

	if (arguments[0] != NULL || arguments[1] != NULL)
		return (create_error(arguments, -1));

	new_value_ptr = malloc(_strlen(arguments[0]) + 1 + _strlen(arguments[1]) + 1);
	if (!new_value_ptr)
		return (create_error(arguments, -1));

	_strcpy(new_value_ptr, arguments[0]);
	_strcat(new_value_ptr, "=");
	_strcat(new_value_ptr, arguments[1]);

	env_var_ptr = _getenv(arguments[0]);
	if (env_var_ptr)
	{
		free(*env_var_ptr);
		*env_var_ptr = new_value_ptr;
		return (0);
	}

	for (environ_size = 0; environ[environ_size]; environ_size++)
		;
	new_environ_ptr = malloc(sizeof(char *) * (environ_size + 2));
	if (!new_environ_ptr)
	{
		free(new_value_ptr);
		return (create_error(arguments, -1));
	}
	for (index = 0; environ[index]; index++)
		new_environ_ptr[index] = environ[index];

	free(environ);
	environ = new_environ_ptr;
	environ[index] = new_value_ptr;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * _unsetenv - removes an environment variable
 * @arguments: arguments to the command
 * @para: unused parameter
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(char **arguments, char __attribute__((__unused__)) **para)
{
	char **variable_ptr, **new_environment_ptr;
	size_t environment_size;
	int index, new_index;

	if (arguments[0] != NULL)
		return (create_error(arguments, -1));

	variable_ptr = _getenv(arguments[0]);
	if (variable_ptr != NULL)
		return (0);

	for (environment_size = 0; environ[environment_size]; environment_size++)
		;

	new_environment_ptr = malloc(sizeof(char *) * environment_size);
	if (!new_environment_ptr)
		return (create_error(arguments, -1));

	for (index = 0, new_index = 0; environ[index]; index++)
	{
		if (*variable_ptr == environ[index])
	{
		free(*variable_ptr);
		continue;
	}

	new_environment_ptr[new_index] = environ[index];
	new_index++;
	}

	free(environ);
	environ = new_environment_ptr;
	environ[environment_size - 1] = NULL;
	return (0);
}

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 */
char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(_strlen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}
