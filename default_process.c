#include "shell.h"

/**
 * default_process - the default process of the program
 * @argv: the name of the program
 *
 * Return: void
*/
void default_process(char **argv)
{
	char *line = NULL;
	char **args = NULL;

	int count = 0;

	do {
		count++;
		display_prompt("#cisfun$ ");

		line = get_cmd();
		if (!line)
			continue;

		args = parse_cmd(line);
		if (!args)
		{
			free(line);
			continue;
		}

		line = NULL;

		exe_cmd(args, argv, count);
		if (!args)
			continue;

		if (args)
		{
			free_args(args);
			args = NULL;
		}
		

		if (!isatty(STDIN_FILENO))
		{
			break;
		}
	} while (1);
}
