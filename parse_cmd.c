#include "shell.h"

char **parse_cmd(char *cmd);

/**
 * parse_cmd - parsing the command into tokens
 * @cmd: the command line
 *
 * Return: The command-line as an array of strings
 *         Otherwise, return NULL
 */

char **parse_cmd(char *cmd)
{
	char **args = NULL;
	int i, j = 0, token_count = 0;
	char *cmd_cpy = NULL, *token = NULL;
	char delimiters[] = " \n\t\r";


	/* duplicate the memory and copy it to cmd_cpy */
	cmd_cpy = _strdup(cmd);
	if (!cmd_cpy)
		return (NULL);

	token = NULL;

	/* Tokenize each string and count the tokens */
	token = strtok(cmd_cpy, delimiters);

	if (!token)
	{
		free(cmd_cpy);
		cmd_cpy = NULL;
		return (NULL);
	}

	while (token)
	{
		token_count++;
		token = strtok(NULL, delimiters);
	}
	/* Increment one token for the last element (NULL) */
	token_count++;

	free(cmd_cpy);
	cmd_cpy = NULL;

	cmd_cpy = _strdup(cmd);
	if (!cmd_cpy)
	{
		free(cmd);
		return (NULL);
	}

	/* Create an array of pointers of ntokens */
	args = malloc(sizeof(char *) * token_count);
	if (!args)
	{
		free(cmd_cpy);
		return (NULL);
	}

	/* Tokenize and duplicate each string to the new memory */
	token = strtok(cmd_cpy, delimiters);

	for (i = 0; token; i++)
	{
		args[i] = _strdup(token);

		if (!args[i])
		{
			while (j < i)
			{
				free(args[j]);
				args[j] = NULL;
				j++;
			}

			free(cmd_cpy);
			free(args);
			args = NULL;
			cmd_cpy = NULL;
			return (NULL);
		}

		token = strtok(NULL, delimiters);
	}

	args[i] = NULL;


	free(cmd);
	free(cmd_cpy);
	cmd_cpy = NULL;

	return (args);
}
