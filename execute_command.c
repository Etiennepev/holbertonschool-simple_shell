#include "shell.h"

/**
 * execute_command - Exécute une commande.
 * @args: Tableau de tokens représentant la commande et ses arguments.
 *
 * Return: 0
 */
int execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to create process");
		exit(41);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute");
			exit(97);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
