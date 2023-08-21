#include "shell.h"

/**
 * search_path - search the PATH of the command
 * @arg: is the command
 *
 * Return: 0 on success OTHERWISE return -1
*/
int search_path(char **arg)
{
	struct stat st;
	int state;
	char *current_dir;
	path *list;

	/* Seg fault here when enters a command like qqwwqq */
	state = access(*arg, F_OK);

	if (state == 0)
		return (state);

	list = create_list();

	while (list->next_dir)
	{
		current_dir = list->dir;
		_strcat(current_dir, "/");
		_strcat(current_dir, *arg);
		_strcat(current_dir, "\0");

		if (stat(current_dir, &st) == 0)
		{
			state = 0;
			break;
		}
		else
			state = -1;

		list = list->next_dir;
	}

	*arg = current_dir;
	return (state);
}
