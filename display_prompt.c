#include "shell.h"

/**
 * display_prompt - displays prompt to the terminal
 * Return: void
 **/
void display_prompt(void)
{
	char prompt[256];
	char *p_prompt;
	size_t p_prompt_len;

	if (!isatty(STDIN_FILENO))
		return;

	p_prompt = getcwd(prompt, sizeof(prompt));

	p_prompt_len = _strlen(p_prompt);

	if (!p_prompt)
		write(STDOUT_FILENO, "$ ", 2);
	else
	{
		write(STDOUT_FILENO, p_prompt, p_prompt_len);
		_putchar('$');
		_putchar(' ');
	}
}
