#include "shell.h"

void path_cmds(char **args, char **argv, int count);

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

	if (!args)
		return;

	is_path = search_path(&args[0]);

	if (is_path == -1 && args)
	{
		fprintf(stderr, "%s: %d: %s: %s\n", argv[0], count, args[0], "not found");
		return;
	}

	if (is_path == -1)
	{
		fprintf(stderr, "%s: %d: %s: %s\n", argv[0], count, args[0], "not found");
		return;
	}

	id = fork();

	if (id == -1)
		return;

	if (id == 0)
	{
		if (is_path == 0 && !args[1])
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}

		}
		if (execve(args[0], args, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
