#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>

/**
 * struct path_s - linked list structure for PATH variable
 * @directory: directory to lookup
 * @next: pointer to the next node
 */

typedef struct path_s
{
	char *directory;
	struct path_s *next;
} linked_t;

/* prompt */
void shellPrompt(void);

/* cd handling */
int cd_handler(char **array, char **env);
int exit_handler(char **array, char *line, char *newline, int cmd_count);
int checkBuiltins(char **ar, char **env, char *line, char *newline, int cdnum);

/* tokenization */

char **tokenize(char *line);

/* env handling */
int env_handler(char **env);
char *path_handler(char *command, char **env);
char *_getenv(const char *name, char **env);

/* execute */
int execute_cmd(char **ar, char **env, char **av, char *line, char *nline,
		int cmd_count);
/* string function */
char *_strdup(char *str);
char *_concatenate(char *concat, char *s1, char *s2);
int _strlen(char *s);
char *_strconcat(char *s1, char *s2);
int _strcmp(char *str1, char *str2);

/* realloc */
char *_realloc(char *ptr);

/* signals */
void ctrlc_handler(int signal_num);
int ctrld_handler(char *main_input);
/*linkedlist */
linked_t *create_linkedt(char *path_var);
linked_t *addnodes_list(char *new_str, linked_t *new_list);

/* error */
void error_handler(char **argv, char **tokens, int cmdcount, char *line,
			char *trimmed);
/* atio function */
int _atoi(char *str);

/* print */
char *print_int(int num);
int tens_place(int i, char *s);
/* freeing of memory space */
void free_list(linked_t *head);
void free_tokens(char **t_array);
void free_all(char *line, char *newline, char **t_array);

#endif /* SHELL_H */
