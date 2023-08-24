#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

/* STRUCTURES */
/**
 * struct Path - The env PATH
 * @dir: The directory
 * @next_dir: The next directory
*/
typedef struct Path
{
	char *dir;
	struct Path *next_dir;
} path;

/**
 * struct Builtins - The Builtins cmds
 * @cmd: The command-line
 * @builtin_fp: The function will be executed
*/
typedef struct Builtins
{
	char *cmd;
	void (*builtin_fp)(char **, char **, int);
} builtins;

/* MAIN PROTOTYPES */
void default_process(char **argv);
void display_prompt(void);
char *get_cmd(void);
char **parse_cmd(char *cmd);
void path_cmds(char **args, char **argv, int count);
void free_args(char *line, char **args);

/* PATH COMMANDS */
path *path_list(void);
void free_path_list(path *head);
char *_getenv(const char *name);
char *append_cmd(char *cmd, char *path);
int search_path(char **arg, path **list);

/* BUILTINS */
builtins **builtins_list(void);

void (*exe_cmd(char **args))(char **, char **, int);

void __exit(char **args, char **argv, int count);
void _env(char **args __attribute__((unused)), char **argv, int count);


/* HELPERS PROTOTYPES */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);

#endif
