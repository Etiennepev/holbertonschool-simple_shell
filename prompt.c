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

/**
 * main - Point d'entrée du shell.
 * @argc: Nombre d'arguments.
 * @argv: Tableau des arguments.
 *
 * Return: Toujours 0.
 */
int main(int argc, char **argv)
{
	char *str;
    char **args;

    (void)argc;
    (void)argv;

    while (1)
    {
        write(1, "#cisfun$ ", 9);
 		
        str = read_input_line();
        args = split_strings(str);

        if (args[0] != NULL)
            execute_command(args);

        free(args);
        free(str);
    }

    return 0;
}
