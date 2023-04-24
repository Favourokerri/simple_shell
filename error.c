#include "shell.h"

/**
 * error_handler - writes an error message if command is not found
 * @argv: the array of passed in function argument strings
 * @tokens: array of tokens entered by the user
 * @cmdcount: the number of commands entered
 * @line: user input
 * @trimmed: user input without the newline character
 */
void error_handler(char **argv, char **tokens, int cmdcount, char *line,
			char *trimmed)
{
	char *count_str;

	count_str = print_int(cmdcount);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count_str, _strlen(count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "command not found\n", 18);
	free(count_str);
	free_all(line, trimmed, tokens);
	exit(0);
}
