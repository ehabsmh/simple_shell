#include "shell.h"

/**
 * search_path - search the PATH of the command
 * @arg: is the command
 * @list: list of PATH
 *
 * Return: 0 on success OTHERWISE return -1
*/
int search_path(char **arg, path **list)
{
	struct stat st;
	int is_path;
	char *current_dir, *appended_cmd;
	path *list_cpy;

	/* Seg fault here when enters a command like qqwwqq */
	is_path = access(*arg, F_OK);

	if (is_path == 0)
		return (is_path);

	*list = path_list();
	list_cpy = (*list);

	while (list_cpy)
	{
		current_dir = list_cpy->dir;
		appended_cmd = append_cmd(arg[0], current_dir);
		if (stat(appended_cmd, &st) == 0)
		{
			is_path = 0;
			break;
		}
		list_cpy = list_cpy->next_dir;
	}

	if (is_path == 0)
	{
		arg[0] = _strdup(appended_cmd); /* if still memory leak check this */

		free(appended_cmd);

		if (!arg[0])
			is_path = -1;
	}

	return (is_path);
}
