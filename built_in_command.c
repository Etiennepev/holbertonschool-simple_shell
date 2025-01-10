#include "shell.h"

/**
* _env - print the current environnement variable.
* @envp: environnement variable.
**/

void _env(char **envp)
{
	int i = 0;

	for (; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}

/**
* exit_builtin - free args and exit the program.
* @args: arguments to free.
**/

void exit_builtin(char **args, char *input)
{
	int i = 0;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(input);
	exit(0);
}
