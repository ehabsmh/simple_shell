#include "shell.h"

path *path_list(void);

/**
 * create_list - creates a list
 *
 * Return: pointer to the head of Linked list
*/
path *path_list(void)
{
	char *str_path, *token, *env;
	path *head, *head_cpy, *new_dir;

	env = _getenv("PATH");
	/* duplicate the string in PATH to a new memory */
	str_path = _strdup(env);
	if (!str_path)
		return (NULL);

	free(env);

	token = strtok(str_path, ":");

	head = malloc(sizeof(path));
	if (!head)
	{
		free(str_path);
		return (NULL);
	}

	head->dir = _strdup(token);
	if (head->dir == NULL)
	{
		free(str_path);
		free(head);
		return (NULL);
	}

	head->next_dir = NULL;
	head_cpy = head;

	while (token)
	{
		new_dir = malloc(sizeof(path));
		if (!new_dir)
		{
			free_path_list(head);
			return (NULL);
		}

		token = strtok(NULL, ":");
		if (token)
			new_dir->dir = _strdup(token);
		else
			new_dir->dir = NULL;

		if (token && !new_dir->dir)
		{
			free_path_list(head);
			return (NULL);
		}

		new_dir->next_dir = NULL;
		head_cpy->next_dir = new_dir;
		head_cpy = new_dir;
	}

	free(str_path);
	return (head);
}
