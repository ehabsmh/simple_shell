#include "shell.h"

/**
 * free_args - freeing the command
 * @line: the command-line
 * @args: the command-line after parsing
 *
 * Return: void
*/
void free_args(char *line, char **args)
{
	int i;

	if (!line || !args)
		return;

	free(line);

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
