#include "shell.h"

int search_path(char **arg);

/**
 * search_path - search the PATH of the command
 * @arg: is the command
 *
 * Return: 0 on success OTHERWISE return -1
*/
int search_path(char **arg)
{
	struct stat st;
	int is_path;
	char *current_dir = NULL, *appended_cmd = NULL;
	path *list = NULL, *list_cpy = NULL;

	/* Seg fault here when enters a command like qqwwqq */
	is_path = access(*arg, F_OK);

	if (is_path == 0)
		return (is_path);

	list = path_list();
	if (!list)
		return (-1);

	list_cpy = list;

	while (list_cpy)
	{
		current_dir = list_cpy->dir;
		appended_cmd = append_cmd(arg[0], current_dir);
		if (!appended_cmd)
		{
			is_path = -1;
			break;
		}
		if (stat(appended_cmd, &st) == 0)
		{
			is_path = 0;
			break;
		}
		free(appended_cmd);
		appended_cmd = NULL;
		list_cpy = list_cpy->next_dir;
	}

	if (is_path == 0)
	{
		if (arg[0])
			free(arg[0]);

		arg[0] = _strdup(appended_cmd);

		free(appended_cmd);
		appended_cmd = NULL;

		if (!arg[0])
			is_path = -1;
	}

	free_path_list(list);
	return (is_path);
}
