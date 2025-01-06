#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 *
 * Return: 0 on success, 1 on failure
 *
 * Description: Reads a line of input, splits it into tokens,
 * creates a child process using fork, and executes the command
 * in the child process using execve. Handles errors and frees
 * allocated memory before returning.
 */

int execute_command(void)
{
	pid_t pid;
	int status;
	char **tokens_array;

	tokens_array = split_strings(read_line());
	if (tokens_array == NULL)
		return (1);

	pid = fork();
	if (pid == -1)
	{
		free(tokens_array);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(tokens_array[0], tokens_array, NULL) == -1)
		{
			perror("Error");
			free(tokens_array);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(tokens_array);
	return (0);
}
