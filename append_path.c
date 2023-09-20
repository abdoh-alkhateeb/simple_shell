#include "main.h"

/**
 * append_path - a function that appends path to command.
 * @path: path of command.
 * @command: entered command.
 *
 * Return: command path on success, otherwise NULL.
 */
char *append_path(char *path, char *command)
{
	char *buffer;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buffer = malloc(sizeof(char) * (strlen(path) + strlen(command) + 2));

	if (!buffer)
		return (NULL);

	for (i = 0; path[i]; i++)
		buffer[i] = path[i];

	if (path[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}

	for (j = 0; command[j]; j++)
		buffer[i + j] = command[j];

	buffer[i + j] = '\0';

	return (buffer);
}
