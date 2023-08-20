#include "shell.h"

/**
 * create_list - creates a list
 *
 * Return: pointer to the head of Linked list
*/
path *create_list(void)
{
	char *str_path, *token;
	path *head, *head_cpy, *new_dir;

	/* duplicate the string in PATH to a new memory */
	str_path = _strdup(_getenv("PATH"));

	token = strtok(str_path, ":");

	head = malloc(sizeof(path));
	if (!head)
		return (NULL);

	head->dir = _strdup(token);
	head->next_dir = NULL;
	head_cpy = head;

	while (token)
	{
		new_dir = malloc(sizeof(path));
		if (!new_dir)
		return (NULL);

		token = strtok(NULL, ":");
		new_dir->dir = _strdup(token);
		new_dir->next_dir = NULL;
		head_cpy->next_dir = new_dir;
		head_cpy = new_dir;
	}

	return (head);
}
