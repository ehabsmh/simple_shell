#include "shell.h"

#define env environ

/**
 * _getenv - returns the env variables by name
 * @name: The name of the variable
 *
 * Return: the value of the variable
 * OTHERWISE return NULL
*/
char *_getenv(const char *name)
{

	char *env_value;
	int i, j, env_len, is_same = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; env[i][j] != '='; j++)
		{
			if (name[j] != env[i][j])
				is_same = 0;
			else
				is_same = 1;
		}

		if (is_same)
		{
			env_len = _strlen(env[i] + j + 1);
			break;
		}
	}

	if (is_same)
	{
		env_value = malloc((env_len + 1) * sizeof(char));
		if (!env_value)
			return (NULL);

		_strcpy(env_value, env[i] + j + 1);
		env_value[env_len] = '\0';
	}
	else
		return (NULL);

	return (env_value);
}
