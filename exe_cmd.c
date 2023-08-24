#include "shell.h"

/**
 * exe_cmd - returns function pointer
 * @args: the command
 *
 * Return: fptr
*/
void (*exe_cmd(char **args))(char **args, char **argv, int count)
{
	int i;

	builtins **list = builtins_list();

	if (!args)
		return (NULL);

	for (i = 0; list[i]; i++)
	{
		if (_strcmp(args[0], list[i]->cmd) == 0)
		{
			return (list[i]->builtin_fp);
		}
	}

	return (path_cmds);
}
