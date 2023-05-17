#include "shell.h"

/**
 * read_line - Reads a line of input from the user
 *
 * Return: A pointer to the line of input
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize;

    bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}
