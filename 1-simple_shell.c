#include "main.h"


/**
 * main - Main entry point for the program
 *
 * Return: Always returns 0 indicating success
 */



int main(void)
{
    char *buff = NULL; /* Buffer for user input */
    size_t count = 0; /* Size of the buffer */
    ssize_t tread; /* Number of characters read */

    while (1)
    {
        write(STDOUT_FILENO, "magic_simpleshell# ", 18); /* Print shell prompt */
        tread = getline(&buff, &count, stdin); /* Read user input */
        if (tread == -1)
        {
            perror("Exiting shell");
            free(buff); /* Free allocated memory */
            exit(EXIT_FAILURE); /* Exit the shell on failure */
        }
        else if (tread == 0)
        {
            printf("End of file reached. Exiting shell.\n");
            free(buff); /* Free allocated memory */
            exit(EXIT_SUCCESS); /* Exit the shell on EOF */
        }
        else
        {
            buff[strcspn(buff, "\n")] = '\0'; /* Remove newline character from input */
        }

        /* Tokenize the input to separate command and arguments */
        char *token;
        token = strtok(buff, " ");
        if (token != NULL)
        {
            char *args[MAX_ARGS + 1]; /* Maximum of MAX_ARGS arguments + NULL */
            int i = 0;
            args[i++] = token;

            while ((token = strtok(NULL, " ")) != NULL && i < MAX_ARGS)
            {
                args[i++] = token;
            }
            args[i] = NULL; /* Null-terminate the argument list */

            /* Execute the command with arguments */
            if (find_and_execute_command(args) == -1)
            {
                printf("Command not found: %s\n", args[0]);
            }
        }

        free(buff); /* Free allocated memory */
        buff = NULL; /* Reset buffer pointer */
    }

    return 0;
}



/**
 * search_and_exe_commd - Finds and executes a command
 * @args: Array of command arguments
 *
 * Return: 0 on success, -1 on failure
 */


int search_and_exe_commd(char *args[])
{
    char *path = getenv("PATH");
    if (path == NULL)
    {
        perror("Unable to get PATH");
        return -1;
    }
    

    /* Adds  command execution logic here */

if (execvp(args[0], args) == -1)
    {
        perror("Command execution failed");
        return -1;
    }


    return 0;
}

