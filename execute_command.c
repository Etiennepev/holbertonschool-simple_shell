#include "shell.h"

/**
 * execute_command - Execute a command.
 * @args: An array of tokens represent the command of args.
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
