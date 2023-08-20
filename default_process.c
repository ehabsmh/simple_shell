#include "shell.h"

/**
 * default_process - the default process of the program
 *
 * Return: void
*/
void default_process(void)
{
	char *line;
	char **args;

	do {
		display_prompt();
		line = get_cmd();
		args = parse_cmd(line);
		exe_cmd(args);
		free_args(line, args);
	} while (1);
}
