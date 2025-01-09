#include "shell.h"

/**
 * main - input.
 * @argc: Numbers of args.
 * @argv: Array of args.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *str;
	char **args;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$ ");

		str = read_input_line();
		args = split_strings(str);

		if (args[0] != NULL)
			execute_command(args);
		free_array(args);
	}
	free(str);

	return (0);
}
