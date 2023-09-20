#include "main.h"

/**
 * check_command - a function that checks if a command is a builtin.
 * @command: tokenized command.
 * @buffer: commandline buffer.
 *
 * Return: 1 if command excuted, 0 otherwise.
 */
int check_command(char **command, char *buffer)
{
	if (handle_builtin(command, buffer))
		return (1);
	else if (**command == '/')
	{
		execute(command[0], command);
		return (1);
	}
	return (0);
}
