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

int history_count;

#define MAX_COMMAND_LENGTH 100

/*string manipulation functions */
char *read_command(void);
char **parse_command(char *input);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *destination, const char *source);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);

/* signals handler */
void sig_handler(int sig);

/* environ functions */
int _env(char **arguments, char __attribute__((__unused__)) **unused_para);
int _setenv(char **args, char __attribute__((__unused__)) **unused_para);
char **_getenv(const char *s);
int _unsetenv(char **arguments, char __attribute__((__unused__)) **para);
char **_copyenv(void);
void free_env(void);

/* environ errors */
char *env_error_message(char **args);

/* atio function && itoa */
int num_len(int num);
char *_itoa(int num);
int _atoi(char *s);
void reverse(const char *str);

/* errors and error messages */
int create_error(char **args, int err);
char *env_error(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* tokenization */
int token_lenght(char *str, char *delim);
char **_strtok(char *str, char *delim);

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/* alias struct */

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* built in alias */
int _alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
int (*get_builtin(char *command))(char **args, char **front);

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/*linked list */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

/* Exit */
int _exitt(char **args, char **front);

/* change directory */
int _cd(char **args, char __attribute__((__unused__)) **front);

/* arguements */
void free_args(char **args, char **front);

#endif /* SHELL_H */
