#include "main.h"

/**
 * handle_exit - a function that handles the exit builtin.
 * @command: tokenized command.
 * @buffer: commandline buffer.
 *
 * Return: nothing.
 */
void handle_exit(char **command, char *buffer)
{
	free(buffer);

	free_buffer(command);

	exit(EXIT_SUCCESS);
}
