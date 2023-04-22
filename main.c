#include "shell.h"

/**
 * main - entry point
 * @argc: command line arguement
 * @argv: command line arguement
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	int func_ret = 0;

	int retn;

	int *ptr_retn = &retn;

	char *prompt = "~s ";

	char *newline = "\n";

	name = argv[0];
	history_count = 1;
	signal(SIGINT, sig_handler);

	return (0);
}
