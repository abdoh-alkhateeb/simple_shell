#include "main.h"

/**
 * check_path - a function that checks whether path is valid.
 * @path: tokenized path.
 * @command: entered command.
 *
 * Return: path appended with command on success, NULL otherwise.
 */
char *check_path(char **path, char *command)
{
	int i;
	char *output;

	for (i = 0; path[i]; i++)
	{
		output = append_path(path[i], command);

		if (access(output, F_OK | X_OK) == 0)
			return (output);

		free(output);
	}

	return (NULL);
}
