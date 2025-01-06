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

int prompt(void)
{
	char *buffer = NULL;
	size_t buffsize;
	char *character;

	while (1)
	{
		printf("#cisfun$ ");

		character = read_line();

		split_strings(character);

		if (split_strings(character) == -1)
		{
			printf("\n");
			break;
		}
		printf("%s", buffer);

		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}
	}
	free(buffer);
	return (0);
}
