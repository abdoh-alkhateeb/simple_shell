#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* env */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* utils */
void handle_signal(int);
void prompt_user(void);
char **tokenize(char *);
int check_command(char **, char *);
int handle_builtin(char **, char *);
char *check_path(char **, char *);
char *find_path(void);
char *append_path(char *, char *);
void execute(char *, char **);
void handle_exit(char **, char *);
void handle_env(void);
void free_buffer(char **);

/* structs */

/**
 * builtin - stores builtins.
 * @env: env builtin.
 * @exit: exit builtin.
 *
 * Description: a struct that stores builtins for comparison purposes.
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * flags - stores flags.
 * @interactive: indicates whether shell is interactive.
 *
 * Description: a struct that stores flags for shell.
 */
struct flags
{
	bool interactive;
} flags;

#endif /* _MAIN_H_ */
