#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **split_strings(char *str);
char *read_line(void);
int execute_command(char **command_args);
int main(void);

#endif
