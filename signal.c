#include "shell.h"

/**
 * ctrlc_handler - Ctrl+C handler
 * @signal_num: signal number received
 * Return: void
 */

void ctrlc_handler(int signal_num)
{
	(void)signal_num;

	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * ctrld_handler - Ctrl+D handler
 * @main_input: the main line buffer to free
 * Return: 0 on success
 */

int ctrld_handler(char *main_input)
{
	free(main_input);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
