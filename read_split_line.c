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
	if (nread > 0 && buf[nread - 1] == '\n')
		buf[nread - 1] = '\0';
	return (buf);
}
/**
 * split_strings - Splits a string into an array of tokens
 * @str: String to be split
 *
 * Return: Pointer to an array of tokens, or NULL on failure
 */
char **split_strings(char *str)
{
	char *token = NULL;
	char **array = NULL;
	size_t capacity = 10;
	size_t i = 0;
	size_t k;

	array = malloc(sizeof(char *) * capacity);
	if (array == NULL)
	{
		perror("Malloc failed");
		exit(1);
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		if (i >= capacity)
			capacity *= 2;
		if (i >= capacity)
		{
			char **new_array = malloc(sizeof(char *) * capacity);

			if (new_array == NULL)
			{
				perror("Malloc failed");
				exit(1);
			}
			for (k = 0; k < i; k++)
				new_array[k] = array[k];
			free(array);
			array = new_array;
		}
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
