#include "shell.h"

/**
 * path_cmds - creates child process and executes the cmd
 * @args: the arguments to be executed
 * @argv: program name
 * @count: count of execution
 * Return: void
*/
void path_cmds(char **args, char **argv, int count)
{
	int is_path;
	pid_t id;

	path *list = NULL;

	if (!args)
		return;

	id = fork();

	if (id == -1)
		return;

	if (id == 0)
	{
		is_path = search_path(&args[0], &list);

		if (is_path == 0 && list)
		{
			free_path_list(list);
		}

		if (is_path == -1)
		{
			fprintf(stderr, "%s: %d: %s\n", argv[0], count, "not found");
			return;
		}

		execve(args[0], args, NULL);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
