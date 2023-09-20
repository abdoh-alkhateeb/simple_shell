#include "main.h"

/**
 * prompt_user - a function that prompts user if shell is in interactive mode.
 *
 * Return: nothing.
 */
void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
