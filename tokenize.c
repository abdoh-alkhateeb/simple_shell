#include "main.h"

/**
 * tokenize - a function that creates tokens from given commandline.
 * @line: line to be tokenized.
 *
 * Return: array of tokens.
 */
char **tokenize(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buf = strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (strchr(delim, *bufp) != NULL && flag == 0)
			tokensize++, flag = 1;
		else if (strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	if (tokens == NULL)
		return (NULL);
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
