#include "shell.h"

/**
 * display_prompt - displays prompt to the terminal
 * Return: void
 **/
void display_prompt(char *location)
{	
	if (!isatty(STDIN_FILENO))
		return;

	write(STDOUT_FILENO, location, _strlen(location));
}
