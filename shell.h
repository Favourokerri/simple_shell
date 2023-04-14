#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

char *read_command(void);


#endif /* SHELL_H */
