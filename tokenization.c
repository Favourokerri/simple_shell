#include "shell.h"
#define DELIMITERS " \t\0"

/**
 * tokenize - splits user input into tokens and stores into array
 * @line: input string to split
 *
 * Return: array of strings(tokens)
 */

char **tokenize(char *line)
{
	int i = 0;
	int t_count = 0;
	char **t_array;
	char *token, *t_copy;

	if (line == NULL)
		return (NULL);
	while (*(line + i) != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'
				       || line[i + 1] == '\t'))
			t_count++;
		i++;
	}

	i = 0;
	t_array = malloc(sizeof(char *) * (t_count + 1));
	if (t_array == NULL)
		return (NULL);
	token = strtok(line, DELIMITERS);
	while (token != NULL)
	{
		t_copy = _strdup(token);
		if (t_copy == NULL)
		{
			free(t_array);
			return (NULL);
		}
		*(t_array + i) = t_copy;
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	*(t_array + i) = NULL;
	return (t_array);
}
