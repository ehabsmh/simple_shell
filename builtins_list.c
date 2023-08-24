#include "shell.h"

/**
 * builtins_list - list of builtin functions
 *
 * Return: The list
*/
builtins **builtins_list(void)
{
	int i;
	builtins **main_list;

	builtins list_of_builtins[3] = {
		{"exit", __exit}, {"env", _env}, {NULL, NULL}
	};

	main_list = malloc(sizeof(builtins *) * 3);
	if (!main_list)
		return (NULL);

	for (i = 0; list_of_builtins[i].cmd; i++)
	{
		main_list[i] = malloc(sizeof(builtins));
		if (!main_list[i])
			return (NULL);

		main_list[i]->cmd = list_of_builtins[i].cmd;
		main_list[i]->builtin_fp = list_of_builtins[i].builtin_fp;
	}

	return (main_list);
}
