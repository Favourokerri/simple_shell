#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Global environemnt variable */
extern char **environ;

/* Global program name */

char *name;
/* Global history counter */

int hist;

#define MAX_COMMAND_LENGTH 100

/*string manipulation functions */
char *read_command(void);
char **parse_command(char *input);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *destination, const char *source);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);

/* signals handler */
void sig_handler(int sig);

/* environ functions */
int _env(char **arguments, char __attribute__((__unused__)) **unused_para);


#endif /* SHELL_H */
