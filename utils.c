#include "shell.h"

/**
 * _strlen - Evaluates the length of a string
 * @s: array of strings (decayed into a pointer when passed as an argument)
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	unsigned int str_len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		str_len++;
	}

	return (str_len);
}

/**
 * _strcpy - copies the string pointed to by src
 * to the buffer pointed to by dest
 *
 * @dest: Pointer to the buffer
 * @src: pointer to string
 *
 * Return: pointer to the string which copied
 */
char *_strcpy(char *dest, char *src)
{
	char *str;

	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	str = dest;

	return (str);
}

/**
 * _strdup - duplicate of `str` to a newely space in memory
 * @str: string to be duplicated
 *
 * Return: NULL if malloc fails and if `str` is equal to NULL
 * OTHERWISE Return pointer to the newely allocated memory
 */
char *_strdup(char *str)
{
	char *str_cpy;
	int str_len;

	if (str == NULL)
		return (NULL);

	str_len = _strlen(str);

	str_cpy = malloc(sizeof(char) * (str_len + 1));

	if (str_cpy == NULL)
		return (NULL);

	_strcpy(str_cpy, str);

	return (str_cpy);
}

/**
 * *_strcat - concatenates @src to @dest
 * @src: the source string to append to @dest
 * @dest: the destiation string to be concatenated upon
 * Return:pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int index = 0;
	int dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];
	return (dest);
}

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 *
 *Return: The integer value of the comverted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {

		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}
