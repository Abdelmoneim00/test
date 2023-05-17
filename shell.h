#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELIMITER " \t\r\n\a"

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int shell_exit(char **args);
int shell_cd(char **args);
int shell_help(char **args);

#endif /* SHELL_H */
