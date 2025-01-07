#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 *
 * Return: 0 on success, 1 on failure
 *
 * @command_args: The first element is the command to execute, followed by its
 *                arguments.
 *
 * Description: Reads a line of input, splits it into tokens,
 * creates a child process using fork, and executes the command
 * in the child process using execve. Handles errors and frees
 * allocated memory before returning.
 */

int execute_command(char *parsed_args[])
{
	pid_t pid;
	int status;

	parsed_args = split_strings(read_line());
	if (parsed_args == NULL)
		return (1);

	pid = fork();
	if (pid == -1)
	{
		free(parsed_args);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(parsed_args[0], parsed_args, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	return (0);
}
