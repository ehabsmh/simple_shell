#include "shell.h"

/**
 * exe_cmd - returns function pointer
 * @args: the command
 * @argv: vector
 * @count: total number of the program execution
 * Return: fptr
*/
void exe_cmd(char **args, char **argv, int count)
{
	if (!args)
		return;

	if (_strcmp(args[0], "exit") == 0)
	{
		__exit(args);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		_env();
	}
	else
	{
		path_cmds(args, argv, count);
	}
}
