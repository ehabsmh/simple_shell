#include "shell.h"

/**
 * exe_cmd - creates child process and executes the cmd
 * @args: the arguments to be executed
 *
 * Return: void
*/
void exe_cmd(char **args)
{
	int state;
	pid_t id;

	if (!args)
		return;

	state = search_path(&args[0]);

	if (state == -1)
	{
		perror("./hsh");
		return;
	}

	id = fork();

	if (id == -1)
		return;

	if (id == 0)
	{
		execve(args[0], args, NULL);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
