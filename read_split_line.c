#include "shell.h"

/**
 * read_input_line - Lit une ligne depuis l'entrée standard.
 *
 * Return: La ligne lue (doit être libérée par l'appelant).
 */
char *read_input_line(void)
{
    char *buf = NULL;
    size_t count = 0;
    ssize_t nread;

    nread = getline(&buf, &count, stdin);
    if (nread == -1)
    {
        perror("Exiting shell");
        free(buf);
        exit(1);
    }
    return buf;
}

/**
 * split_strings - Splits a string into an array of tokens
 * @str: String to be split
 *
 * Return: Pointer to an array of tokens, or NULL on failure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **split_strings(char *str)
{
    char **tokens_array = malloc(sizeof(char *) * 10);
    char *token;
    int i = 0, capacity = 10;

    if (tokens_array == NULL)
    {
        perror("Malloc failed");
        exit(1);
    }

    token = strtok(str, " \n");
    while (token)
    {
        if (i >= capacity)
        {
            capacity *= 2;
            tokens_array = _realloc(tokens_array, sizeof(char *) * i, sizeof(char *) * capacity);
            if (tokens_array == NULL)
            {
                perror("Realloc failed");
                exit(1);
            }
        }
        tokens_array[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    tokens_array[i] = NULL;

    return (tokens_array);
}
