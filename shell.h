#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char **split_strings(char *str);
char *read_input_line(void);
int execute_command(char **args);
int main(int argc, char **argv);
char *_getenv(const char *name);
char *get_file_path(char *file_name);
void free_array(char **tokens);

#endif
