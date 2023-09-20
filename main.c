#include "main.h"

/**
 * main - program entry point.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 always.
 */
int main(int argc, char **argv)
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;

	argc = argc;

	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffer(command), free_buffer(paths), free(pathcommand);
		prompt_user();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;

		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';

		command = tokenize(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (check_command(command, line))
			continue;

		path = find_path();
		paths = tokenize(path);
		pathcommand = check_path(paths, command[0]);

		if (!pathcommand)
			perror(argv[0]);
		else
			execute(pathcommand, command);
	}

	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);

	free(line);
	return (0);
}
