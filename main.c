#include "shell.h"

/**
 * main - entry point
 * @ac: number of arguments passed
 * @av: array of strings of arguments passed
 * @env: the current environment
 * Return: 0 when EOF is reached - user presses Ctrl + D
 */
int main(int ac, char **av, char **env)
{
	char *line, *newline;
	size_t len = 0;
	ssize_t lineSize;
	char **t_array;
	int cmdnum = 0;

	(void)ac, (void)av;
	while (1)
	{
		line = NULL;
		len = 0;
		cmdnum++;
		if (isatty(STDIN_FILENO) == 1)
			shellPrompt();
		signal(SIGINT, ctrlc_handler);
		lineSize = getline(&line, &len, stdin);
		if (lineSize == EOF || lineSize == -1)
			return (ctrld_handler(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		newline = _realloc(line);
		if (newline == NULL)
		{
			free(line);
			return (0);
		}
		t_array = tokenize(newline);
		if (t_array == NULL)
		{
			free(line);
			free(newline);
			return (0);
		}
		execute_cmd(t_array, env, av, line, newline, cmdnum);
		free_all(line, newline, t_array);
	}
}

