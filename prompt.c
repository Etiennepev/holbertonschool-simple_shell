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
