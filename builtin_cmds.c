#include "shell.h"

/**
 * __exit - exits the shell
 * @args: The command-line
 *
 * Return: void
*/
void __exit(char **args)
{
	int status;

	if (!args)
		return;

	if (args[1])
	{
		if (_atoi(args[1]) < 0)
		{
			status = 2;
			exit(status);
		}
		status = _atoi(args[1]);
		free_args(args);
		exit(status);
	}

	free_args(args);
	exit(0);
}

/**
 * _env - prints the env
 *
 * Return: void
*/
void _env(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
	}
}
