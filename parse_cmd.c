#include "shell.h"

/**
 * parse_cmd - parsing the command into tokens
 * @cmd: the command line
 * 
 * Return: The command-line as an array of strings
 *         Otherwise, return NULL
 **/
char **parse_cmd(char *cmd)
{
	char **args;
	int i, token_count;
	char *cmd_cpy, *token;
	char delimiters[] = " \n\t\r";

	if (!cmd)
		return (NULL);

	/* duplicate the memory and copy it to cmd_cpy */
	cmd_cpy = _strdup(cmd);

	token = NULL;
	token_count = 0;

	/* Tokenize the first element before the delimiter */
	token = strtok(cmd_cpy, delimiters);

	/* Tokenize each string and count the tokens */
	while (token)
	{
		token_count++;
		token = strtok(NULL, delimiters);
	}

	/* Increment one token for the last element (NULL) */
	token_count++;

	free(cmd_cpy);

	/* Create an array of pointers of ntokens */
	args = malloc(sizeof(char *) * token_count);
	if (!args)
		return (NULL);

	/* Tokenize and duplicate each string to the new memory */
	token = strtok(cmd, delimiters);
	for (i = 0; i < token_count; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimiters);
	}
	args[i] = NULL;

	return (args);
}
