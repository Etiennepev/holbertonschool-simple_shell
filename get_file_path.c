#include "shell.h"
/**
 * get_file_path - Get's the full path of the file
 * @file_name: Argument name
 *
 * Return: The full path argument to the file
 */
char *get_file_path(char *file_name)
{
	char *path = NULL;
	char *directory = NULL, *path_copy = NULL, *full_path = NULL;
	size_t len;

	path = _getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup failed");
		return (NULL);
	}
	directory = strtok(path, ":");
	while (directory != NULL)
	{
		len = strlen(directory) + strlen(file_name) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			perror("malloc failed");
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, directory);
		strcat(full_path, "/");
		strcat(full_path, file_name);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
