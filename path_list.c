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
	{
		free(env);
		return (NULL);
	}

	token = strtok(str_path, ":");

	head = malloc(sizeof(path));
	if (!head)
	{
		free(env);
		free(str_path);
		return (NULL);
	}

	head->dir = _strdup(token);
	if (head->dir == NULL)
	{
		free(env);
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
			free(env);
			free(str_path);
			return (NULL);
		}

		token = strtok(NULL, ":");
		if (token)
		{
			new_dir->dir = _strdup(token);
			if (!new_dir->dir)
			{
				free(new_dir);
				free(env);
				free(str_path);
				return (NULL);
			}
		}
		else
			new_dir->dir = NULL;

		new_dir->next_dir = NULL;
		head_cpy->next_dir = new_dir;
		head_cpy = new_dir;
	}

	free(env);
	free(str_path);
	return (head);
}
