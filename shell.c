#include "shell.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: vector
 * @env: env variables
 *
 * Return: always 0 (success)
*/
int main(int argc, char **argv, char **env)
{
	(void) argc, (void) env;

	default_process(argv);
	return (0);
}
