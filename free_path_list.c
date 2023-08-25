#include "shell.h"

/**
 * free_path_list - frees a path list
 * @head: A pointer to the first node of the list
 */
void free_path_list(path *head)
{
	path *temp;

	path *traverse = head;

	if (!head)
		return;

	while (traverse)
	{
		temp = traverse;
		traverse = traverse->next_dir;

		if (temp != NULL)
		{
			free(temp->dir);
			free(temp);
		}
	}

	traverse = NULL;
	temp = NULL;
}
