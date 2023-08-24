#include "shell.h"

/**
 * free_path_list - frees a path list
 * @head: A pointer to the first node of the list
 */
void free_path_list(path *head)
{
	path *traverse = head;

	if (!head)
		return;

	while (traverse)
	{
		traverse = traverse->next_dir;
		free(head->dir);
		free(head);
		head = traverse;
	}

	head = NULL;
}
