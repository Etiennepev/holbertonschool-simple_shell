#include "shell.h"

/*
* main - infinite boucle of the shell.
* @argc : number of arguments.
* @argv : array of string of arguments.
* @envp : array of environnement variable.
* Return: 0.
*/

int main(int argc, char **argv, char *envp[])
{
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	int i;

	(void)argc, (void)argv;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("Prompt: ");
			nread = read_input(&input, &len);

			if (nread == -1)
			{
				perror("Exit the shell");
				break;
			}
			input[nread - 1] = '\0';
			args = split_input(input);
			if (args[0])
				execute_command(args, envp, input);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
		}
	}
	else
	{
		nread = read_input(&input, &len);
		while (nread != -1)
		{
			input[nread - 1] = '\0';
			args = split_input(input);
			if (args[0])
				execute_command(args, envp, input);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			nread = read_input(&input, &len);
		}
	}
	free(input);
	return (0);
}

/*
* read_input - read the user input.
* @input : double pointer to store the user input.
* @len : pointer to thesize of the buffer.
* Return: the number of reader characters or -1 if error.
*/

ssize_t read_input(char **input, size_t *len)
{
	ssize_t nread;

	if (*input == NULL)
		*len = 0;

	nread = getline(input, len, stdin);
	if (nread == -1)
	{
		return (-1);
	}
	return (nread);
}

/**
* split_input - divide the line into arguments.
* @input: pointer to the user input.
* Return: array of arguments or NULL if error.
**/

char **split_input(char *input)
{
	int bufsize = 10, i = 0, j;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Allocation memory failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " ");
	while (token)
	{
		tokens[i] = malloc(strlen(token) + 1);
		if (!tokens[i])
		{
			perror("Allocation memory failed");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(token);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);
		i++;
		if (i >= bufsize)
		{
			bufsize += 10;
			tokens = _realloc(tokens, (bufsize - 10) * sizeof(char *),
							  bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Allocation memory failed");
				for (j = 0; j < i; j++)
					free(tokens[j]);
				free(tokens);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/*
* execute_command - execute command.
* @args : double pointer to store the args.
* @envp : array of environnement variable.
* @input : user input.
*/

void execute_command(char **args, char *envp[], char *input)
{
	pid_t pid;
	char *exec_path;
	int status;

	if (strcmp(args[0], "env") == 0)
	{
		_env(envp);
		return;
	}
	else if (strcmp(args[0], "exit") == 0)
		exit_builtin(args, input);
	if (args[0][0] == '/' || args[0][0] == '.')
		exec_path = strdup(args[0]);
	else
		exec_path = manage_path(envp, args[0]);
	if (exec_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return;
	}
	if (args[0] == NULL)
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(exec_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(exec_path, args, envp) == -1)
		{
			perror("Execute error");
			free(exec_path);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(exec_path);
}

/**
* manage_path - find the full path of a command.
* @envp: array of environment variables.
* @file_name: the name of the command to find.
* Return: the full path of the command or NULL if not found.
**/

char *manage_path(char *envp[], char *file_name)
{
	char *path_copy, *token;
	char *absolute_path = NULL;
	char *path = _getenv(envp);

	if (path == NULL)
	{
		perror("Path not found");
		return (NULL);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	while (token)
	{
		if (absolute_path)
		{
			free(absolute_path);
			absolute_path = NULL;
		}
		absolute_path = malloc(strlen(token) + strlen(file_name) + 2);
		if (!absolute_path)
		{
			perror("malloc failed");
			free(path_copy);
			exit(EXIT_FAILURE);
		}
		strcpy(absolute_path, token);
		strcat(absolute_path, "/");
		strcat(absolute_path, file_name);
		if (access(absolute_path, X_OK))
		{
			free(path_copy);
			return (absolute_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_copy)
		free(absolute_path);
	return (NULL);
}
