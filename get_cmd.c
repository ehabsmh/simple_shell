#include "shell.h"

/**
 * get_cmd - Reads the command
 * Return: line in successful
 * OTHERWISE return -1
*/
char *get_cmd(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t chars_read;

	chars_read = getline(&line, &line_size, stdin);

	if (chars_read == -1)
	{
		/* check for end of file ctrl+D */
		_putchar('\n');
		free(line);
		line = NULL;
		exit(EXIT_SUCCESS);
	}

	/* check the end of line and replace it with '\0' */
	if (line[chars_read - 1] == '\n')
		line[chars_read - 1] = '\0';

	/* if there is no line return null */
	if (line[0] == '\0')
		return (NULL);

	return (line);
}
