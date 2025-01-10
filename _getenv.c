#include "shell.h"

/**
 * _getenv - Searches for an environment variable by name.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
	int i, name_len;
	char *env_var;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = strdup(environ[i]);
		name_len = strlen(name);
		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
			return (env_var + name_len + 1);
	}
	free(env_var);
	return (NULL);
}
