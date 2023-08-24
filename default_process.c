#include "shell.h"

/**
 * default_process - the default process of the program
 * @argv: the name of the program
 *
 * Return: void
*/
void default_process(char **argv)
{
	char *line;
	char **args;
	void (*fptr)(char **, char **, int);

	int count = 0;

	do {
		count++;
		display_prompt();
		/* Extract the command-line */
		line = get_cmd();
		/* The command-line is parsed to array of pointers */
		args = parse_cmd(line);
		free(line);
		line = NULL;
		fptr = exe_cmd(args);
		if (!fptr)
			continue;

		(*fptr)(args, argv, count);

		if (!isatty(STDIN_FILENO))
		{
			break;
		}
	} while (1);
}
