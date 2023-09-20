#include "main.h"

/**
 * execute - a function that executes given command.
 * @command: command to execute.
 * @argument_list: array of pointers to arguments.
 *
 * Return: nothing.
 */
void execute(char *command, char **argument_list)
{
	pid_t child_pid = fork();

	if (child_pid < 0)
		perror(command);
	if (child_pid == 0)
	{
		execve(command, argument_list, environ);

		perror(command);

		free(command);
		free_buffer(argument_list);

		exit(98);
	}
	else
		wait(NULL);
}
