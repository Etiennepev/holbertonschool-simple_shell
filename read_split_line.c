#include "shell.h"

/**
 * read_input_line - read a line from the input.
 *
 * Return: line read.
 */
char *read_input_line(void)
{
	char *buf = NULL;
	size_t count = 0;
	ssize_t nread;

	nread = getline(&buf, &count, stdin);
	if (nread == -1)
	{
		perror("Exiting shell");
		free(buf);
		exit(0);
	}
	return (buf);
}

/**
 * split_strings - Splits a string into an array of tokens
 * @str: String to be split
 *
 * Return: Pointer to an array of tokens, or NULL on failure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_strings(char *str)
{
	char **tokens_array = malloc(strlen(str) * sizeof(char *));
	char *token;
	int i = 0;
	

	if (tokens_array == NULL)
	{
		perror("Malloc failed");
		exit(0);
	}

	token = strtok(str, " ");
	while (token)
	{
		tokens_array[i] = strdup(token);
		if (tokens_array[i])
		{
			while (i >= 0)
			{
				free(tokens_array[i]);
				i--;
			}
			free(tokens_array);
			return (NULL);
		}
		token = strtok(NULL, " \n");
		i++;
	}

	tokens_array[i] = NULL;

	return (tokens_array);
}
