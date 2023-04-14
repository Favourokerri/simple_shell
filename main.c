#include "shell.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */

int main() {
    char *input;

    char **arguments;

    while (1) 
    {
       printf("#cisfun$ ");
       input  = read_command();
       if(input == NULL)
       {
	       printf("exiting the shell\n");
		       return (-1);
       }
	input[strcspn(input, "\n")] = '\0';
       	printf("%s\n", input);
        free(input);
    }
    return 0;
}
