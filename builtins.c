#include "main.h"

/*
 * builtin_cd - changes the current working directory
 * @args: argument passed with the cd command
 *
 * This function changes the current working directory based on the provided argument.
 * If no argument is provided, it changes the directory to the user's home directory.
 * Returns: None
 */
void builtin_cd(char *args)
{
    if (args == NULL)
    {
        char *home = getenv("HOME");

        if (home == NULL)
        {
            perror("cd: HOME environment variable is not set\n");
        }
        else
        {
            if (chdir(home) != 0)
            {
                perror("could not change directory");
            }
        }
    }
    else
    {
        if (chdir(args) != 0)
        {
            perror("could not change directory");
        }
    }
}

/*
 * builtin_exit - exits the shell
 *
 * This function prints a message indicating that the shell is exiting,
 * sleeps for 2 seconds, and then exits the shell with a status of 0.
 * Returns: None
 */
void builtin_exit(void)
{
    printf("\nExiting shell...\n");
    sleep(2);
    exit(0);
}

