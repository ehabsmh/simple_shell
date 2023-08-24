#include "shell.h"

#define env environ

/**
 * __exit - exits the shell
 * @args: The command-line
 * @argv: unused
 * @count: unused
 *
 * Return: void
*/
void __exit(char **args, char **argv, int count)
{
	int status;
	(void)argv;
	(void)count;

	if (args[1] && _atoi(args[1]) < 0)
	{
		return;
	}

	if (args[1])
	{
		status = _atoi(args[1]);
		exit(status);
	}

	_puts("Exiting...");
	exit(0);
}

/**
 * _env - prints the env
 * @args: The command-line
 * @argv: unused
 * @count: unused
 *
 * Return: void
*/
void _env(char **args __attribute__((unused)), char **argv, int count)
{
	int i;
	(void)argv;
	(void)count;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
	}
}
