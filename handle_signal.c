#include "main.h"

/**
 * handle_signal- it keeps track is interactive mode
 * @signal: given signal.
 *
 * Return: nothing
 */
void handle_signal(int signal)
{
	signal = signal;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
