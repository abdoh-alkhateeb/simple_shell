#include "main.h"

/**
 * handle_env - a function that handles the env builtin.
 *
 * Return: nothing.
 */
void handle_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, (const void *)environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
