#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char **split_strings(char *str);
char *read_input_line(void);
int execute_command(char **args);
int main(int argc, char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
