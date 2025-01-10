#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
void exit_builtin(char **args, char *input);
void _env(char **envp);
int main(int argc, char **argv, char *envp[]);
ssize_t read_input(char **input, size_t *len);
char **split_input(char *input);
void execute_command(char **args, char *envp[], char *input);
char *manage_path(char *envp[], char *file_name);
char *_getenv(char *envp[]);

#endif
