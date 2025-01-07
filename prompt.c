#include "shell.h"

/**
 * prompt - Displays a prompt and handles user input
 *
 * Return: 0 on success
 *
 * Description: Continuously displays a shell prompt "#cisfun$ ",
 * reads user input, splits it into tokens, and handles commands.
 * Exits the loop if the user types "exit\n" or if an error occurs.
 * Frees allocated memory before exiting.
 */

int main(void)
{
	char *character = NULL;
	char **parsed_args;

	while (1)
	{
		printf("#cisfun$ ");

	

		parsed_args = split_strings(character);

		if (parsed_args == NULL)
		{
			perror("Error\n");
			continue;
		}
		if (strcmp(parsed_args[0], "exit") == 0)
		{
			free(character);
			free(parsed_args);
		}
		execute_command(parsed_args);

	free(parsed_args);
	}
	free(character);
	return (0);
}
