#include "shell.h"

/**
 * execute - Executes a command with the given arguments
 * @args: The arguments to the command
 *
 * Return: 1 if the shell should continue running, 0 if it should exit
 */
int execute(char **args)
{
    pid_t pid;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0)
        return shell_exit(args);

    if (strcmp(args[0], "cd") == 0)
        return shell_cd(args);

    if (strcmp(args[0], "help") == 0)
        return shell_help(args);

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        wait(NULL);
    }

    return 1;
}

/**
 * shell_exit - Exits the shell
 * @args: The arguments to the exit command
 *
 * Return: 0
 */
int shell_exit(char **args)
{
    printf("Used %s: shell exited\n", args[0]);
    return 0;
}

/**
 * shell_cd - Changes the current working directory
 * @args: The arguments to the cd command
 *
 * Return: 1
 */
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "Expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("Error");
        }
    }
    return 1;
}

/**
 * shell_help - Displays help information for the shell
 * @args: The arguments to the help command
 *
 * Return: 1
 */
int shell_help(char **args)
{
    printf("Used command %s:\n", args[0]);
    printf("Simple shell program\n");
    printf("Commands:\n");
    printf("cd [directory] - Change the current working directory\n");
    printf("help - Display this help message\n");
    printf("exit - Exit the shell\n");
    return 1;
}
