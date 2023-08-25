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


/* MAIN PROTOTYPES */
void default_process(char **argv);
void display_prompt(char *location);
char *get_cmd(void);
char **parse_cmd(char *cmd);
void path_cmds(char **args, char **argv, int count);
void free_args(char **args);

/* PATH COMMANDS */
path *path_list(void);
void free_path_list(path *head);
char *append_cmd(char *cmd, char *path);
int search_path(char **arg);

/* BUILTINS */

void exe_cmd(char **args, char **argv, int count);
void __exit(char **args);
void _env(void);
void _cd(char **args);



/* HELPERS PROTOTYPES */
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);

#endif
