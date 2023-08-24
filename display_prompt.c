#include "shell.h"

/**
 * display_prompt - displays prompt to the terminal
 * Return: void
 **/
void display_prompt(void)
{
	if (!isatty(STDIN_FILENO))
		return;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
