#include "shell.h"

/**
 * execute_command - Execute a command.
 * @args: An array of tokens represent the command of args.
 *
 * Return: 0
 */
int execute_command(char **args)
{
	pid_t child_pid;
	int status;
	char *path;

	path = get_file_path(args[0]);
	if (path == NULL)
	{
		perror("path not found");
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to create process");
		exit(0);
	}

	if (child_pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("Failed to execute");
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
	return (0);
}

/*
* free_array - 
*
*
*/

void free_array(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
