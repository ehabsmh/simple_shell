#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/* Structures */
typedef struct Path path;

  struct Path
 {
   char *dir;
   path *next_dir;
 };



/* MAIN PROTOTYPES */
void default_process();
void display_prompt(void);
char *get_cmd(void);
char **parse_cmd(char *cmd);
void exe_cmd(char **args);
void free_args(char *line, char **args);
path *create_list(void);
char *_getenv(const char *name);
int search_path(char **arg);


/HELPERS PROTOTYPES/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);


#endif
