#include "main.h"

/**
 * handle_builtin - a function that handles execution of builtin functions.
 * @command: tokenized command.
 * @buffer: commandline buffer.
 *
 * Return: 1 if executed, 0 otherwise.
 */
int handle_builtin(char **command, char *buffer)
{
	struct builtin builtin = {"env", "exit"};

	if (strcmp(*command, builtin.env) == 0)
	{
		handle_env();
		return (1);
	}
	else if (strcmp(*command, builtin.exit) == 0)
	{
		handle_exit(command, buffer);
		return (1);
	}

	return (0);
}
