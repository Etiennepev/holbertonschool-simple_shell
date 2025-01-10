#include "shell.h"

/**
* _getenv- get the value of an environnement variable.
* @name : of the variable to search.
* @envp : array of environnement variable.
* Return: pointer to the value of the variable of NULL.
**/

char *_getenv(char *envp[])
{
	int i = 0;

	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}
