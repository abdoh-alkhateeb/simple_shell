#include "main.h"

/**
 * find_path - a function that finds path from global enviroment.
 *
 * Return: path if found, NULL otherwise.
 */
char *find_path(void)
{
	int i;
	char *path;

	while (*environ)
	{
		if (strncmp(*environ, "PATH=", 5) == 0)
		{
			path = *environ;

			for (i = 0; *path && i < 5; i++)
				path++;

			return (path);
		}

		environ++;
	}

	return (NULL);
}
