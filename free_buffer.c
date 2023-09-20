#include "main.h"

/**
 * free_buffer - a function that frees a buffer.
 * @buffer: buffer to be freed.
 *
 * Return: nothing.
 */
void free_buffer(char **buffer)
{
	int i;

	if (buffer == NULL)
		return;

	for (i = 0; buffer[i]; i++)
		free(buffer[i]);

	free(buffer);
}
