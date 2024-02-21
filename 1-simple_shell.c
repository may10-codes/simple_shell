#include "main.h"


/**
 * main - Main entry point for the program
 *
 * Return: Always returns 0 indicating success
 */
int main(void)
{
    char *buff = NULL;
    size_t count = 0;
    ssize_t tread;

    while (1)
    {
        write(STDOUT_FILENO, "magic_simpleshell# ", 18);
        tread = getline(&buff, &count, stdin);
        if (tread == -1)
        {
            perror("Exiting shell");
            free(buff); /* Free allocated memory */
            exit(EXIT_FAILURE);
        }
        else if (tread == 0)
        {
            printf("End of file reached. Exiting shell.\n");
            free(buff); /* Free allocated memory */
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("%s", buff);
        }
        free(buff); /* Free allocated memory */
        buff = NULL; /* Reset buffer pointer */
    }

    /* Tokenize the input to separate command and arguments */
    
    {
        char *token;
        token = strtok(buff, " \n");
        if (token != NULL)
        {
            char *args[10]; /* Assuming maximum of 10 arguments */
            int i = 0;
            args[i++] = token;

            while ((token = strtok(NULL, " \n")) != NULL && i < 9)
            {
                args[i++] = token;
            }
            args[i] = NULL; /* Null-terminate the argument list */

            /* Execute the command with arguments */
            execvp(args[0], args);
            perror("Command execution failed");
        }
    }

    free(buff); /* Free allocated memory */
    buff = NULL; /* Reset buffer pointer */

    return 0;
}

