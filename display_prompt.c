#include "shell.h"

/**
 * display_prompt - displays prompt to the terminal
 * Return: void
 **/
void display_prompt(void)
{
	char prompt[256];
	char *p_prompt;

	p_prompt = getcwd(prompt, sizeof(prompt));

	if (!p_prompt)
		printf("$ ");
	else
		printf("%s$ ", p_prompt);
}
