#include "shell.h"

/**
 * read_line - Reads a line of input from standard input
 *
 * Return: Pointer to the line read, or NULL on failure
 *
 * Description: Uses getline to read a line from stdin.
 * Allocates memory for the buffer dynamically. Frees the buffer
 * and returns NULL if getline fails.
 */

char *read_line(void)
{
	char *buffer = NULL;
	size_t buffsize;

	if (getline(&buffer, &buffsize, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/**
 * split_strings - Splits a string into an array of tokens
 * @str: String to be split
 *
 * Return: Pointer to an array of tokens, or NULL on failure
 *
 * Description: Reads a line of input, allocates memory for
 * an array of tokens, and splits the string using spaces as
 * delimiters. Handles memory allocation errors.
 */

char **split_strings(char *str)
{
	char **tokens_array;
	char *token;
	int i = 0;

	str = read_line();
	if (str == NULL)
		return (NULL);

	tokens_array = malloc((25) * sizeof(char *));
	if (tokens_array == NULL)
	{
		free(str);
		return (NULL);
	}
	token = strtok(str, " ");
	if (tokens_array == NULL)
		return (NULL);

	while (token)
	{
		tokens_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tokens_array[i] = NULL;
	return (tokens_array);
}
