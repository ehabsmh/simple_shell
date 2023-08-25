#include "shell.h"

/**
 * free_args - freeing the command
 * @args: the command-line after parsing
 *
 * Return: void
*/
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	if (args)
	{

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
	}
}
