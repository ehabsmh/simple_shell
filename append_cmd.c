#include "shell.h"

/**
 * append_cmd - appends the cmd to the path
 * @cmd: the command-line
 * @path: The directory
 * 
 * Return: the appended command
*/
char *append_cmd(char *cmd, char *path)
{
  char *appended_cmd;
  size_t cmd_len, path_len, appended_cmd_len;

  if (!cmd || !path)
    return (NULL);

  cmd_len = _strlen(cmd);
  path_len = _strlen(path);

  appended_cmd = malloc(sizeof(char) * (cmd_len + path_len + 2));
  if (!appended_cmd)
    return (NULL);

  _strcat(appended_cmd, path);

  if (appended_cmd && appended_cmd[path_len - 1] != '/')
    _strcat(appended_cmd, "/");

  _strcat(appended_cmd, cmd);

  appended_cmd_len = _strlen(appended_cmd); 

  appended_cmd[appended_cmd_len] = '\0';

  return (appended_cmd);
}
