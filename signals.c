#include "shell.h"

/**
 * sig_handler - prints to the screen after a signal is detected
 * @sig: the signal to be printed
 */

void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 3);
}
